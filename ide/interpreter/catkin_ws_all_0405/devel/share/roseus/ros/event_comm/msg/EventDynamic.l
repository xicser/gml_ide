;; Auto-generated. Do not edit!


(when (boundp 'event_comm::EventDynamic)
  (if (not (find-package "EVENT_COMM"))
    (make-package "EVENT_COMM"))
  (shadow 'EventDynamic (find-package "EVENT_COMM")))
(unless (find-package "EVENT_COMM::EVENTDYNAMIC")
  (make-package "EVENT_COMM::EVENTDYNAMIC"))

(in-package "ROS")
;;//! \htmlinclude EventDynamic.msg.html


(defclass event_comm::EventDynamic
  :super ros::object
  :slots (_base _dynamicEventName _dynamicType _dynamicInfo ))

(defmethod event_comm::EventDynamic
  (:init
   (&key
    ((:base __base) (instance event_comm::EventBase :init))
    ((:dynamicEventName __dynamicEventName) "")
    ((:dynamicType __dynamicType) "")
    ((:dynamicInfo __dynamicInfo) "")
    )
   (send-super :init)
   (setq _base __base)
   (setq _dynamicEventName (string __dynamicEventName))
   (setq _dynamicType (string __dynamicType))
   (setq _dynamicInfo (string __dynamicInfo))
   self)
  (:base
   (&rest __base)
   (if (keywordp (car __base))
       (send* _base __base)
     (progn
       (if __base (setq _base (car __base)))
       _base)))
  (:dynamicEventName
   (&optional __dynamicEventName)
   (if __dynamicEventName (setq _dynamicEventName __dynamicEventName)) _dynamicEventName)
  (:dynamicType
   (&optional __dynamicType)
   (if __dynamicType (setq _dynamicType __dynamicType)) _dynamicType)
  (:dynamicInfo
   (&optional __dynamicInfo)
   (if __dynamicInfo (setq _dynamicInfo __dynamicInfo)) _dynamicInfo)
  (:serialization-length
   ()
   (+
    ;; event_comm/EventBase _base
    (send _base :serialization-length)
    ;; string _dynamicEventName
    4 (length _dynamicEventName)
    ;; string _dynamicType
    4 (length _dynamicType)
    ;; string _dynamicInfo
    4 (length _dynamicInfo)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; event_comm/EventBase _base
       (send _base :serialize s)
     ;; string _dynamicEventName
       (write-long (length _dynamicEventName) s) (princ _dynamicEventName s)
     ;; string _dynamicType
       (write-long (length _dynamicType) s) (princ _dynamicType s)
     ;; string _dynamicInfo
       (write-long (length _dynamicInfo) s) (princ _dynamicInfo s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; event_comm/EventBase _base
     (send _base :deserialize buf ptr-) (incf ptr- (send _base :serialization-length))
   ;; string _dynamicEventName
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _dynamicEventName (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _dynamicType
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _dynamicType (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _dynamicInfo
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _dynamicInfo (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get event_comm::EventDynamic :md5sum-) "2ccc20968a7c0d24ca90b858f3122b4b")
(setf (get event_comm::EventDynamic :datatype-) "event_comm/EventDynamic")
(setf (get event_comm::EventDynamic :definition-)
      "event_comm/EventBase base
string dynamicEventName
string dynamicType
string dynamicInfo
================================================================================
MSG: event_comm/EventBase
std_msgs/Header header
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



(provide :event_comm/EventDynamic "2ccc20968a7c0d24ca90b858f3122b4b")


