# Strategy 2: Use group_by instead of reduce
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
        yearly_activity: (
          group_by(.commit.author.date[0:4])
          | map({
              key: .[0].commit.author.date[0:4],
              value: {
                total_commits: length,
                monthly_activity: (
                  group_by(.commit.author.date[0:7])
                  | map({
                      key: .[0].commit.author.date[0:7],
                      value: { total_commits: length }
                    })
                  | from_entries
                )
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
