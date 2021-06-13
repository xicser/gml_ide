;; Auto-generated. Do not edit!


(when (boundp 'event_comm::EventCollaborative)
  (if (not (find-package "EVENT_COMM"))
    (make-package "EVENT_COMM"))
  (shadow 'EventCollaborative (find-package "EVENT_COMM")))
(unless (find-package "EVENT_COMM::EVENTCOLLABORATIVE")
  (make-package "EVENT_COMM::EVENTCOLLABORATIVE"))

(in-package "ROS")
;;//! \htmlinclude EventCollaborative.msg.html


(defclass event_comm::EventCollaborative
  :super ros::object
  :slots (_base _collaborativeType _collaborativeEvent _collaborativeObject ))

(defmethod event_comm::EventCollaborative
  (:init
   (&key
    ((:base __base) (instance event_comm::EventBase :init))
    ((:collaborativeType __collaborativeType) "")
    ((:collaborativeEvent __collaborativeEvent) "")
    ((:collaborativeObject __collaborativeObject) (let (r) (dotimes (i 0) (push "" r)) r))
    )
   (send-super :init)
   (setq _base __base)
   (setq _collaborativeType (string __collaborativeType))
   (setq _collaborativeEvent (string __collaborativeEvent))
   (setq _collaborativeObject __collaborativeObject)
   self)
  (:base
   (&rest __base)
   (if (keywordp (car __base))
       (send* _base __base)
     (progn
       (if __base (setq _base (car __base)))
       _base)))
  (:collaborativeType
   (&optional __collaborativeType)
   (if __collaborativeType (setq _collaborativeType __collaborativeType)) _collaborativeType)
  (:collaborativeEvent
   (&optional __collaborativeEvent)
   (if __collaborativeEvent (setq _collaborativeEvent __collaborativeEvent)) _collaborativeEvent)
  (:collaborativeObject
   (&optional __collaborativeObject)
   (if __collaborativeObject (setq _collaborativeObject __collaborativeObject)) _collaborativeObject)
  (:serialization-length
   ()
   (+
    ;; event_comm/EventBase _base
    (send _base :serialization-length)
    ;; string _collaborativeType
    4 (length _collaborativeType)
    ;; string _collaborativeEvent
    4 (length _collaborativeEvent)
    ;; string[] _collaborativeObject
    (apply #'+ (mapcar #'(lambda (x) (+ 4 (length x))) _collaborativeObject)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; event_comm/EventBase _base
       (send _base :serialize s)
     ;; string _collaborativeType
       (write-long (length _collaborativeType) s) (princ _collaborativeType s)
     ;; string _collaborativeEvent
       (write-long (length _collaborativeEvent) s) (princ _collaborativeEvent s)
     ;; string[] _collaborativeObject
     (write-long (length _collaborativeObject) s)
     (dolist (elem _collaborativeObject)
       (write-long (length elem) s) (princ elem s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; event_comm/EventBase _base
     (send _base :deserialize buf ptr-) (incf ptr- (send _base :serialization-length))
   ;; string _collaborativeType
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _collaborativeType (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _collaborativeEvent
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _collaborativeEvent (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string[] _collaborativeObject
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _collaborativeObject (make-list n))
     (dotimes (i n)
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setf (elt _collaborativeObject i) (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
     ))
   ;;
   self)
  )

(setf (get event_comm::EventCollaborative :md5sum-) "d067c2bef3be9d576d17bc244d1ee209")
(setf (get event_comm::EventCollaborative :datatype-) "event_comm/EventCollaborative")
(setf (get event_comm::EventCollaborative :definition-)
      "event_comm/EventBase base
string collaborativeType
string collaborativeEvent
string[] collaborativeObject
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



(provide :event_comm/EventCollaborative "d067c2bef3be9d576d17bc244d1ee209")


