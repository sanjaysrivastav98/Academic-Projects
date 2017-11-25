#lang racket

(define (iterator lis ele count)
  (cond
  ((null? lis) '())
  ((= (+ count 1) ele) (car lis))
  (else (iterator (cdr lis) ele (+ count 1)))))

;(define filename
;  (vector-ref (current-command-line-arguments) 0))

(define filename "t2.in")


(define (strtonum lis acc)
    (cond
      ((null? lis) acc)
      (else (strtonum (cdr lis) (append acc (list (string->number (car lis))))) )))
(define nmkl 
(strtonum (string-split (car (file->lines filename))) '() ))
(define N (car nmkl))
(define D (cadr nmkl))
(define K (caddr nmkl))
(define eps (cadddr nmkl))
(define minpts (cadr (cdddr nmkl)))
(define input (cdr (file->lines filename)))
(define (step1res lis acc count)
  (cond
    ((equal? count (+ N 1)) acc)
    (else (step1res (cdr lis)  (append acc  (list (cons count (list (strtonum ( string-split (car lis)) '())) ))) (+ count 1))  )))

(define step1
  (step1res input '() 1)
)


;(define (dist l1 l2 ss count)
 ; (cond
  ;  ((= count (+ D 1)) (sqrt ss))
   ; (else (dist (cdr l1) (cdr l2) (+ ss (expt (- (car l1) (car l2)) 2)) (+ count 1)) )))
(define (ss l1 l2)
  (cond
    ((null? l1 0))
    (else (+ (expt (- (car l1) (car l2)) 2) (ss (cdr l1) (cdr l2))))))
(define (dist l1 l2 s count)
  (sqrt (ss l1 l2)))

(define (eachrowstep2 ele lis acc count)
  (cond
    ((= count (+ N 1)) acc)
    ((= (car ele) (caar lis)) (eachrowstep2 ele (cdr lis) (append acc (list (list count '+inf.0))) (+ count 1)))
    (else (eachrowstep2 ele (cdr lis) (append acc (list (list count (dist (cadr ele) (cadar lis) 0 1)))) (+ count 1)))))

(define (step2res lis1 lis2 acc)
  (cond
    ((null? lis1) acc)
    (else (step2res (cdr lis1) lis2 (append acc (list (eachrowstep2 (car lis1) lis2 '() 1)))))))
(define precision '6)

(define (mysetprecision n p)
  (if (= n +inf.0) +inf.0
      (string->number (~r n #:precision p))
  )
) 

(define (precision_util lst)
  (if (null? lst) '()
      (cons (list (car(car lst)) (mysetprecision (car(cdr(car lst))) precision))  (precision_util (cdr lst))))
)

(define (modify_precision lst)
  (if (null? lst) '()
  (cons (precision_util (car lst)) (modify_precision (cdr lst))))
)



(define step2
 (step2res step1 step1 '()
))


(define (lessthanx lis p acc)
  (cond
    ((null? lis) acc)
    (else
     (cond
       ((list? (car lis))
        (cond
          ((< (cadar lis) p) (lessthanx (cdr lis) p (append acc (list (car lis)))))
          (else (lessthanx (cdr lis) p acc))))
       (else
        (cond
          ((< (car lis) p) (lessthanx (cdr lis) p (append acc (list (car lis)))))
          (else (lessthanx (cdr lis) p acc))))
        ))))
       

(define (greaterthanx lis p acc)
  (cond
    ((null? lis) acc)
    (else
     (cond
       ((list? (car lis))
        (cond
          ((>= (cadar lis) p) (greaterthanx (cdr lis) p (append acc (list (car lis)))))
          (else (greaterthanx (cdr lis) p acc))))
       (else
        (cond
          ((>= (car lis) p) (greaterthanx (cdr lis) p (append acc (list (car lis)))))
          (else (greaterthanx (cdr lis) p acc))))
        ))))

(define (qsort lis)
   (cond
    ((null? lis) '())
    (else
     (cond
       ((list? (car lis)) (append (qsort (lessthanx (cdr lis) (cadar lis) '())) (append (list (car lis)) (qsort (greaterthanx (cdr lis) (cadar lis) '())))))
       (else (append (qsort (lessthanx (cdr lis) (car lis) '())) (append (list (car lis)) (qsort (greaterthanx (cdr lis) (car lis) '())))))))))

(define (kelements lis acc count)
  (cond
    ((= count (+ K 1)) acc)
    (else (kelements (cdr lis) (append acc (list (caar lis))) (+ count 1)))))

    

(define (kNN lis acc)
  (cond
    ((null? lis) acc)
    (else (kNN (cdr lis) (append acc (list (qsort (kelements (qsort (car lis)) '() 1))))))))

(define step3
  (kNN step2 '()))



(define (in1 ele lis)
  (cond
    ((null? lis) #f)
    ((= ele (car lis)) #t)
    (else (in1 ele (cdr lis)))))

(define (intersection lis1 lis2 acc)
  (cond
    ((null? lis1) acc)
    ((in1 (car lis1) lis2)  (intersection (cdr lis1) lis2 (append acc (list (car lis1)))))
    (else (intersection (cdr lis1) lis2 acc))
    ))

(define (in2 ele ind temp count)
  (cond
    ((null? temp) #f)
    ((= count ele) (in1 ind (car temp)))
    (else (in2 ele ind (cdr temp) (+ count 1)))))

(define (weight ele ind temp count res1 res2)
  (cond
    ((null? temp) 0)
    ((= count ele)
     (cond
       ((null? res2 ) (weight ele ind (cdr temp) (+ count 1) (append res1 (car temp)) res2))
       (else (length (intersection (append res1 (car temp)) res2 '())))))
    ((= count ind)
     (cond
       ((null? res1 ) (weight ele ind (cdr temp) (+ count 1) res1 (append res2 (car temp))))
       (else (length (intersection (append res2 (car temp)) res1 '())))))
    (else (weight ele ind (cdr temp) (+ count 1) res1 res2))))
     
(define (allin lis ind temp acc)
  (cond
    ((null? lis ) acc)
    ((in2 (car lis) ind temp 1) (allin (cdr lis) ind temp (append acc (list (list (car lis) (weight (car lis) ind temp 1 '() '()))))))
    (else (allin (cdr lis) ind temp acc))))

(define (ltx lis p acc)
  (cond
    ((null? lis) acc)
    (else
     (cond
          ((<= (cadar lis) p) (ltx (cdr lis) p (append acc (list (car lis)))))
          (else (ltx (cdr lis) p acc))))
        ))
       

(define (gtx lis p acc)
  (cond
    ((null? lis) acc)
    (else
     (cond
          ((> (cadar lis) p) (gtx (cdr lis) p (append acc (list (car lis)))))
          (else (gtx (cdr lis) p acc))))
        ))

(define (qsort2 lis)
   (cond
    ((null? lis) '())
    (else (append (qsort2 (gtx (cdr lis) (cadar lis) '())) (append (list (car lis)) (qsort2 (ltx (cdr lis) (cadar lis) '())))))))

(define (multsort lis)
  (qsort2 lis))

(define (step4res lis temp acc count)
  (cond
    ((null? lis) acc)
    (else (step4res (cdr lis) temp (append acc (list (multsort  (allin (car lis) count temp '())))) (+ count 1)))))

(define step4
  (step4res step3 step3 '() 1))

(define (densityp lis acc)
  (cond
    ((null? lis) acc)
    ((>= (cadar lis) eps) (densityp (cdr lis) (append acc (list (car lis)))))
    (else (densityp (cdr lis) acc))))


(define (densitypoints lis acc)
  (cond
    ((null? lis) acc)
    (else (densitypoints (cdr lis) (append acc (list (densityp (car lis) '())))))))

(define (density lis acc)
  (cond
    ((null? lis) acc)
    (else (density (cdr lis) (append acc (list (length (car lis))))))))
  

(define step5
  (density (densitypoints step4 '()) '())
 )


(define (iscore lis acc count)
  (cond
    ((null? lis) acc)
    ((>= (car lis) minpts) (iscore (cdr lis) (append acc (list (+ count 1))) (+ count 1)))
    (else (iscore (cdr lis) acc (+ count 1)))))

(define step6
  (iscore step5 '() 0))

(define (removeele lis ele acc)
  (cond
    ((null? lis) acc)
    ((= ele (car lis)) (removeele (cdr lis) ele acc))
    (else (removeele (cdr lis) ele (append acc (list (car lis)))))))

(define (removelisfromlis lis1 lis2)
  (cond
    ((null? lis1) lis2)
    (else (removelisfromlis (cdr lis1) (removeele lis2 (car lis1) '())))))

(define (base_cluster edge_lis core_lis acc)
  (cond
    ((null? edge_lis)  acc)
    ((null? core_lis) acc)
    ((in1 (caar edge_lis) core_lis)
     (cond
     ((>= (cadar edge_lis) eps) (base_cluster (cdr edge_lis) (removeele core_lis (caar edge_lis) '()) (append acc (list (caar edge_lis)))))
     (else (base_cluster (cdr edge_lis) core_lis acc)))) 
    (else (base_cluster (cdr edge_lis) core_lis acc))))
   


(define (unique_append lis1 lis2)
  (cond
    ((null? lis2) lis1)
    ((in1 (car lis2) lis1) (unique_append lis1 (cdr lis2)))
    (else (unique_append (append lis1 (list (car lis2))) (cdr lis2)))))

(define (clusterform lis edge_lis core_lis acc)
  (cond
    ((null? lis) acc)
    (else (clusterform (cdr (unique_append lis (base_cluster (iterator edge_lis (car lis) 0) (removelisfromlis acc core_lis) '()))) edge_lis (removelisfromlis acc core_lis) (unique_append acc (base_cluster (iterator edge_lis (car lis) 0) (removelisfromlis acc core_lis) '()))))))   

(define (mult_clusters edge_lis core_points acc count)
  (cond
    ((null? core_points) acc)
    (else (mult_clusters edge_lis (removelisfromlis  (clusterform (list (car core_points)) edge_lis (cdr core_points) (list (car core_points))) core_points) (append acc  (list (list count (qsort (clusterform  (list (car core_points)) edge_lis (cdr core_points) (list (car core_points))))))) (+ count 1)))))

(define step7
  (mult_clusters step4 step6 '() 1))

(define (noise_points core_points acc count)
  (cond
    ((= (+ N 1) count) acc)
    ((in1 count core_points) (noise_points core_points acc (+ count 1)))
    ((= 0 (iterator step5 count 0)) (noise_points core_points (append acc (list count)) (+ count 1)))
    (else (noise_points core_points acc (+ count 1)))))


(define step8
  (noise_points step6 '() 1))

(define (border_points core_points noise acc count)
  (cond
    ((= (+ N 1) count) acc)
    ((in1 count core_points) (border_points core_points noise acc (+ count 1)))
    ((in1 count noise) (border_points core_points noise acc (+ count 1)))
    (else (border_points core_points noise (append acc (list count)) (+ count 1)))))

(define step9
  (border_points step6 step8 '() 1))

(define (samesimi ele lis max temp acc)
  (cond
    ((null? lis) (car acc))
    ((= max (weight (car lis) ele temp 1 '() '())) (samesimi ele (cdr lis) max temp (append acc (list (car lis)))))
    ((< max (weight (car lis) ele temp 1 '() '())) (samesimi ele (cdr lis) (weight (car lis) ele temp 1 '() '()) temp (list (car lis))))
    (else (samesimi ele (cdr lis) max temp acc))))

(define (findCluster cluster toele)
  (cond
    ((in1 toele (cadar cluster)) (caar cluster))
    (else (findCluster (cdr cluster) toele))))

(define (modifiedCluster ele cluster toele acc)
  (cond
    ((null? cluster) acc)
    ((= (caar cluster) (findCluster cluster toele)) (append (append acc (list ( list (caar cluster) (qsort (cons ele (cadar cluster)))))) (cdr cluster)))
    (else (modifiedCluster ele (cdr cluster) toele (append acc (list (car cluster)))))))
                               

(define (borderassign border core_points cluster)
  (cond
    ((null? border) cluster)
    (else (borderassign (cdr border) core_points (modifiedCluster (car border) cluster (samesimi (car border) (cdr core_points) (car core_points) step3 (list (car core_points))) '())))
    ))
(define step10
  (borderassign step9 step6 step7))
          
(provide step1)
(provide step2)
(provide step3)
(provide step4)
(provide step5)
(provide step6)
(provide step7)
(provide step8)
(provide step9)
(provide step10)