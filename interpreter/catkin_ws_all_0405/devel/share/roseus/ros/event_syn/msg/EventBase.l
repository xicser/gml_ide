;; Auto-generated. Do not edit!


(when (boundp 'event_syn::EventBase)
  (if (not (find-package "EVENT_SYN"))
    (make-package "EVENT_SYN"))
  (shadow 'EventBase (find-package "EVENT_SYN")))
(unless (find-package "EVENT_SYN::EVENTBASE")
  (make-package "EVENT_SYN::EVENTBASE"))

(in-package "ROS")
;;//! \htmlinclude EventBase.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass event_syn::EventBase
  :super ros::object
  :slots (_ID _source _begintime _endtime _startPoint _endPoint ))

(defmethod event_syn::EventBase
  (:init
   (&key
    ((:ID __ID) 0)
    ((:source __source) "")
    ((:begintime __begintime) (instance ros::time :init))
    ((:endtime __endtime) (instance ros::time :init))
    ((:startPoint __startPoint) (instance geometry_msgs::Point :init))
    ((:endPoint __endPoint) (instance geometry_msgs::Point :init))
    )
   (send-super :init)
   (setq _ID (round __ID))
   (setq _source (string __source))
   (setq _begintime __begintime)
   (setq _endtime __endtime)
   (setq _startPoint __startPoint)
   (setq _endPoint __endPoint)
   self)
  (:ID
   (&optional __ID)
   (if __ID (setq _ID __ID)) _ID)
  (:source
   (&optional __source)
   (if __source (setq _source __source)) _source)
  (:begintime
   (&optional __begintime)
   (if __begintime (setq _begintime __begintime)) _begintime)
  (:endtime
   (&optional __endtime)
   (if __endtime (setq _endtime __endtime)) _endtime)
  (:startPoint
   (&rest __startPoint)
   (if (keywordp (car __startPoint))
       (send* _startPoint __startPoint)
     (progn
       (if __startPoint (setq _startPoint (car __startPoint)))
       _startPoint)))
  (:endPoint
   (&rest __endPoint)
   (if (keywordp (car __endPoint))
       (send* _endPoint __endPoint)
     (progn
       (if __endPoint (setq _endPoint (car __endPoint)))
       _endPoint)))
  (:serialization-length
   ()
   (+
    ;; int64 _ID
    8
    ;; string _source
    4 (length _source)
    ;; time _begintime
    8
    ;; time _endtime
    8
    ;; geometry_msgs/Point _startPoint
    (send _startPoint :serialization-length)
    ;; geometry_msgs/Point _endPoint
    (send _endPoint :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int64 _ID
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _ID (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _ID) (= (length (_ID . bv)) 2)) ;; bignum
              (write-long (ash (elt (_ID . bv) 0) 0) s)
              (write-long (ash (elt (_ID . bv) 1) -1) s))
             ((and (class _ID) (= (length (_ID . bv)) 1)) ;; big1
              (write-long (elt (_ID . bv) 0) s)
              (write-long (if (>= _ID 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _ID s)(write-long (if (>= _ID 0) 0 #xffffffff) s)))
     ;; string _source
       (write-long (length _source) s) (princ _source s)
     ;; time _begintime
       (write-long (send _begintime :sec) s) (write-long (send _begintime :nsec) s)
     ;; time _endtime
       (write-long (send _endtime :sec) s) (write-long (send _endtime :nsec) s)
     ;; geometry_msgs/Point _startPoint
       (send _startPoint :serialize s)
     ;; geometry_msgs/Point _endPoint
       (send _endPoint :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int64 _ID
#+(or :alpha :irix6 :x86_64)
      (setf _ID (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _ID (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; string _source
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _source (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; time _begintime
     (send _begintime :sec (sys::peek buf ptr- :integer)) (incf ptr- 4)  (send _begintime :nsec (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; time _endtime
     (send _endtime :sec (sys::peek buf ptr- :integer)) (incf ptr- 4)  (send _endtime :nsec (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; geometry_msgs/Point _startPoint
     (send _startPoint :deserialize buf ptr-) (incf ptr- (send _startPoint :serialization-length))
   ;; geometry_msgs/Point _endPoint
     (send _endPoint :deserialize buf ptr-) (incf ptr- (send _endPoint :serialization-length))
   ;;
   self)
  )

(setf (get event_syn::EventBase :md5sum-) "0fd9c6075ee389ae992199348b844526")
(setf (get event_syn::EventBase :datatype-) "event_syn/EventBase")
(setf (get event_syn::EventBase :definition-)
      "int64 ID
string source
time begintime
time endtime
geometry_msgs/Point startPoint
geometry_msgs/Point endPoint
================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

")



(provide :event_syn/EventBase "0fd9c6075ee389ae992199348b844526")


