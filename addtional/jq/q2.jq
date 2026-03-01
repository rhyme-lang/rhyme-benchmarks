# Strategy: Use group_by instead of reduce
# group_by is implemented in C within jq and avoids per-element object reconstruction

[inputs | .[]]
| group_by(.commit.author.name)
| map(
    (.[0].commit.author) as $info |
    {
      key: $info.name,
      value: {
        email: $info.email,
        total_commits: length,
        self_committed: (map(select(.commit.author.name == .commit.committer.name)) | length),
        committed_by_others: (
          map(select(.commit.author.name != .commit.committer.name))
          | group_by(.commit.committer.name)
          | map({
              key: .[0].commit.committer.name,
              value: {
                email: .[0].commit.committer.email,
                commits: length
              }
            })
          | from_entries
        )
      }
    }
  )
| sort_by(-.value.total_commits)
| .[0:5]
| from_entries
