SELECT avg(rating) FROM ratings
JOIN movies ON ratings.movies_id = movies.id
WHERE year = 2012;