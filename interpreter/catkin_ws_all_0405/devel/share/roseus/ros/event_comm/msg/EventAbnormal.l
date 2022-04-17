;; Auto-generated. Do not edit!


(when (boundp 'event_comm::EventAbnormal)
  (if (not (find-package "EVENT_COMM"))
    (make-package "EVENT_COMM"))
  (shadow 'EventAbnormal (find-package "EVENT_COMM")))
(unless (find-package "EVENT_COMM::EVENTABNORMAL")
  (make-package "EVENT_COMM::EVENTABNORMAL"))

(in-package "ROS")
;;//! \htmlinclude EventAbnormal.msg.html


(defclass event_comm::EventAbnormal
  :super ros::object
  :slots ())

(defmethod event_comm::EventAbnormal
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

(setf (get event_comm::EventAbnormal :md5sum-) "d41d8cd98f00b204e9800998ecf8427e")
(setf (get event_comm::EventAbnormal :datatype-) "event_comm/EventAbnormal")
(setf (get event_comm::EventAbnormal :definition-)
      "
")



(provide :event_comm/EventAbnormal "d41d8cd98f00b204e9800998ecf8427e")


