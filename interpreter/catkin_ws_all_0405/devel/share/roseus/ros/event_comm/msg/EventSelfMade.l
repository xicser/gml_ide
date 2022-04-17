;; Auto-generated. Do not edit!


(when (boundp 'event_comm::EventSelfMade)
  (if (not (find-package "EVENT_COMM"))
    (make-package "EVENT_COMM"))
  (shadow 'EventSelfMade (find-package "EVENT_COMM")))
(unless (find-package "EVENT_COMM::EVENTSELFMADE")
  (make-package "EVENT_COMM::EVENTSELFMADE"))

(in-package "ROS")
;;//! \htmlinclude EventSelfMade.msg.html


(defclass event_comm::EventSelfMade
  :super ros::object
  :slots ())

(defmethod event_comm::EventSelfMade
  (:init
   (&key
    )
   (send-super :init)
   self)
  (:serialization-length
   ()
   (+
    0
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;;
   self)
  )

(setf (get event_comm::EventSelfMade :md5sum-) "d41d8cd98f00b204e9800998ecf8427e")
(setf (get event_comm::EventSelfMade :datatype-) "event_comm/EventSelfMade")
(setf (get event_comm::EventSelfMade :definition-)
      "
")



(provide :event_comm/EventSelfMade "d41d8cd98f00b204e9800998ecf8427e")


