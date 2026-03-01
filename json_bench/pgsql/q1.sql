SELECT data -> 'commit' ->> 'collection' AS event, COUNT(*) as count FROM bluesky GROUP BY event ORDER BY count DESC;
