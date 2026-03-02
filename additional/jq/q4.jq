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
        merge_commits: (map(select((.parents | length) > 1)) | length)
      }
    }
  )
| sort_by(-.value.merge_commits)
| .[0:20]
| from_entries
