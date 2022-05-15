(define (domain puzzle)
   (:predicates 
    (position ?p)
	(blocks ?b)
	(right ?p1 - position ?p2 - position)
	(up ?p1 - position ?p2 - position)
	(at ?b - blocks ?p - position)
    (empty ?p - position))

   (:action move_up
       :parameters  (?from ?to ?block)
       :precondition (and  (not (empty ?from)) (empty ?to) (at ?block ?from) (up ?to ?from))
       :effect (and  (not (empty ?to))
		     (at ?block ?to)
		     (not (at ?block ?from))
		     (empty ?from)))

   (:action move_down
       :parameters  (?from ?to ?block)
       :precondition (and  (not (empty ?from)) (empty ?to) (at ?block ?from) (up ?from ?to))
       :effect (and  (not (empty ?to))
		     (at ?block ?to)
		     (not (at ?block ?from))
		     (empty ?from)))
					 
   (:action move_right
       :parameters  (?from ?to ?block)
       :precondition (and  (not (empty ?from)) (empty ?to) (at ?block ?from) (right ?to ?from))
       :effect (and  (not (empty ?to))
		     (at ?block ?to)
		     (not (at ?block ?from))
		     (empty ?from)))

   (:action move_left
       :parameters  (?from ?to ?block)
       :precondition (and  (not (empty ?from)) (empty ?to) (at ?block ?from) (right ?from ?to))
       :effect (and  (not (empty ?to))
		     (at ?block ?to)
		     (not (at ?block ?from))
		     (empty ?from)))
)
