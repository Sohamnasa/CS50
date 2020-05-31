SELET movies.title, rating.ratings FROM movies
JOIN ratings on ratings.movie_id = movies.id
WHERE year = 2010
ORder BY 2 DESC, 1;
