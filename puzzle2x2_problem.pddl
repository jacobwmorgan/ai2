(define (problem puzzle2x2) 
(:domain puzzle)
(:objects row1col1 row1col2 row2col1 row2col2 b1 b2 b3)
(:init
	(at b1 row1col1)
	(at b2 row1col2)
	(at b3 row2col1)
	(empty row2col2)
	(right row1col2 row1col1)
	(right row2col2 row2col1)
	(up row1col1 row2col1)
	(up row1col2 row2col2)
)

(:goal (and
		(at b3 row1col1)
		(at b1 row1col2)
		(at b2 row2col2)
		(empty row2col1)
	)
))