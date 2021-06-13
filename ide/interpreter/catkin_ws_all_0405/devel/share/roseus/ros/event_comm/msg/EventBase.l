;; Auto-generated. Do not edit!


(when (boundp 'event_comm::EventBase)
  (if (not (find-package "EVENT_COMM"))
    (make-package "EVENT_COMM"))
  (shadow 'EventBase (find-package "EVENT_COMM")))
(unless (find-package "EVENT_COMM::EVENTBASE")
  (make-package "EVENT_COMM::EVENTBASE"))

(in-package "ROS")
;;//! \htmlinclude EventBase.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass event_comm::EventBase
  :super ros::object
  :slots (_header _eventID _source _begintime _endtime _startPoint _endPoint ))

(defmethod event_comm::EventBase
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:eventID __eventID) "")
    ((:source __source) "")
    ((:begintime __begintime) (instance ros::time :init))
    ((:endtime __endtime) (instance ros::time :init))
    ((:startPoint __startPoint) (instance geometry_msgs::Point :init))
    ((:endPoint __endPoint) (instance geometry_msgs::Point :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _eventID (string __eventID))
   (setq _source (string __source))
   (setq _begintime __begintime)
   (setq _endtime __endtime)
   (setq _startPoint __startPoint)
   (setq _endPoint __endPoint)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:eventID
   (&optional __eventID)
   (if __eventID (setq _eventID __eventID)) _eventID)
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
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; string _eventID
    4 (length _eventID)
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
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; string _eventID
       (write-long (length _eventID) s) (princ _eventID s)
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
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; string _eventID
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _eventID (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
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

(setf (get event_comm::EventBase :md5sum-) "d88ecb03d6ed3e38611b950e30397c7a")
(setf (get event_comm::EventBase :datatype-) "event_comm/EventBase")
(setf (get event_comm::EventBase :definition-)
      "std_msgs/Header header
string eventID
string source
time begintime
time endtime
geometry_msgs/Point startPoint
geometry_msgs/Point endPoint
================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

")



(provide :event_comm/EventBase "d88ecb03d6ed3e38611b950e30397c7a")


