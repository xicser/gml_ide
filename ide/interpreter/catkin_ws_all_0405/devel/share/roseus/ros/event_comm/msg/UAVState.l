;; Auto-generated. Do not edit!


(when (boundp 'event_comm::UAVState)
  (if (not (find-package "EVENT_COMM"))
    (make-package "EVENT_COMM"))
  (shadow 'UAVState (find-package "EVENT_COMM")))
(unless (find-package "EVENT_COMM::UAVSTATE")
  (make-package "EVENT_COMM::UAVSTATE"))

(in-package "ROS")
;;//! \htmlinclude UAVState.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass event_comm::UAVState
  :super ros::object
  :slots (_UAVnum _Point ))

(defmethod event_comm::UAVState
  (:init
   (&key
    ((:UAVnum __UAVnum) 0)
    ((:Point __Point) (instance geometry_msgs::Point :init))
    )
   (send-super :init)
   (setq _UAVnum (round __UAVnum))
   (setq _Point __Point)
   self)
  (:UAVnum
   (&optional __UAVnum)
   (if __UAVnum (setq _UAVnum __UAVnum)) _UAVnum)
  (:Point
   (&rest __Point)
   (if (keywordp (car __Point))
       (send* _Point __Point)
     (progn
       (if __Point (setq _Point (car __Point)))
       _Point)))
  (:serialization-length
   ()
   (+
    ;; uint64 _UAVnum
    8
    ;; geometry_msgs/Point _Point
    (send _Point :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint64 _UAVnum
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _UAVnum (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _UAVnum) (= (length (_UAVnum . bv)) 2)) ;; bignum
              (write-long (ash (elt (_UAVnum . bv) 0) 0) s)
              (write-long (ash (elt (_UAVnum . bv) 1) -1) s))
             ((and (class _UAVnum) (= (length (_UAVnum . bv)) 1)) ;; big1
              (write-long (elt (_UAVnum . bv) 0) s)
              (write-long (if (>= _UAVnum 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _UAVnum s)(write-long (if (>= _UAVnum 0) 0 #xffffffff) s)))
     ;; geometry_msgs/Point _Point
       (send _Point :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint64 _UAVnum
     
#+(or :alpha :irix6 :x86_64)
      (setf _UAVnum (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _UAVnum (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; geometry_msgs/Point _Point
     (send _Point :deserialize buf ptr-) (incf ptr- (send _Point :serialization-length))
   ;;
   self)
  )

(setf (get event_comm::UAVState :md5sum-) "82010c98432e82a612d456b09f37f399")
(setf (get event_comm::UAVState :datatype-) "event_comm/UAVState")
(setf (get event_comm::UAVState :definition-)
      "uint64 UAVnum
geometry_msgs/Point Point
================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

")



(provide :event_comm/UAVState "82010c98432e82a612d456b09f37f399")


