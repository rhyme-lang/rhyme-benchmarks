# Strategy: Use group_by instead of reduce
# group_by is implemented in C within jq and avoids per-element object reconstruction

[inputs | .[]]
| group_by(.commit.author.date[11:13])
| map({
    key: .[0].commit.author.date[11:13],
    value: {
      total_commits: length,
      unique_authors: (map(.commit.author.name) | unique | length)
    }
  })
| sort_by(-.value.unique_authors)
| from_entries
