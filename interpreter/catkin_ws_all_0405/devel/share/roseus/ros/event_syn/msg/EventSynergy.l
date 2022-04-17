;; Auto-generated. Do not edit!


(when (boundp 'event_syn::EventSynergy)
  (if (not (find-package "EVENT_SYN"))
    (make-package "EVENT_SYN"))
  (shadow 'EventSynergy (find-package "EVENT_SYN")))
(unless (find-package "EVENT_SYN::EVENTSYNERGY")
  (make-package "EVENT_SYN::EVENTSYNERGY"))

(in-package "ROS")
;;//! \htmlinclude EventSynergy.msg.html


(defclass event_syn::EventSynergy
  :super ros::object
  :slots (_base _synergyType _synergyEvent _synergyObject ))

(defmethod event_syn::EventSynergy
  (:init
   (&key
    ((:base __base) (instance event_syn::EventBase :init))
    ((:synergyType __synergyType) "")
    ((:synergyEvent __synergyEvent) "")
    ((:synergyObject __synergyObject) (let (r) (dotimes (i 0) (push "" r)) r))
    )
   (send-super :init)
   (setq _base __base)
   (setq _synergyType (string __synergyType))
   (setq _synergyEvent (string __synergyEvent))
   (setq _synergyObject __synergyObject)
   self)
  (:base
   (&rest __base)
   (if (keywordp (car __base))
       (send* _base __base)
     (progn
       (if __base (setq _base (car __base)))
       _base)))
  (:synergyType
   (&optional __synergyType)
   (if __synergyType (setq _synergyType __synergyType)) _synergyType)
  (:synergyEvent
   (&optional __synergyEvent)
   (if __synergyEvent (setq _synergyEvent __synergyEvent)) _synergyEvent)
  (:synergyObject
   (&optional __synergyObject)
   (if __synergyObject (setq _synergyObject __synergyObject)) _synergyObject)
  (:serialization-length
   ()
   (+
    ;; event_syn/EventBase _base
    (send _base :serialization-length)
    ;; string _synergyType
    4 (length _synergyType)
    ;; string _synergyEvent
    4 (length _synergyEvent)
    ;; string[] _synergyObject
    (apply #'+ (mapcar #'(lambda (x) (+ 4 (length x))) _synergyObject)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; event_syn/EventBase _base
       (send _base :serialize s)
     ;; string _synergyType
       (write-long (length _synergyType) s) (princ _synergyType s)
     ;; string _synergyEvent
       (write-long (length _synergyEvent) s) (princ _synergyEvent s)
     ;; string[] _synergyObject
     (write-long (length _synergyObject) s)
     (dolist (elem _synergyObject)
       (write-long (length elem) s) (princ elem s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; event_syn/EventBase _base
     (send _base :deserialize buf ptr-) (incf ptr- (send _base :serialization-length))
   ;; string _synergyType
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _synergyType (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _synergyEvent
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _synergyEvent (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string[] _synergyObject
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _synergyObject (make-list n))
     (dotimes (i n)
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setf (elt _synergyObject i) (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
     ))
   ;;
   self)
  )

(setf (get event_syn::EventSynergy :md5sum-) "8a522657f44ca2b2a7a97cab253c1c6b")
(setf (get event_syn::EventSynergy :datatype-) "event_syn/EventSynergy")
(setf (get event_syn::EventSynergy :definition-)
      "event_syn/EventBase base
string synergyType
string synergyEvent
string[] synergyObject
================================================================================
MSG: event_syn/EventBase
int64 ID
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



(provide :event_syn/EventSynergy "8a522657f44ca2b2a7a97cab253c1c6b")


