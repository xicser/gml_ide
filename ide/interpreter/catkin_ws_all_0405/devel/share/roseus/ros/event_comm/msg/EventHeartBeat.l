;; Auto-generated. Do not edit!


(when (boundp 'event_comm::EventHeartBeat)
  (if (not (find-package "EVENT_COMM"))
    (make-package "EVENT_COMM"))
  (shadow 'EventHeartBeat (find-package "EVENT_COMM")))
(unless (find-package "EVENT_COMM::EVENTHEARTBEAT")
  (make-package "EVENT_COMM::EVENTHEARTBEAT"))

(in-package "ROS")
;;//! \htmlinclude EventHeartBeat.msg.html


(defclass event_comm::EventHeartBeat
  :super ros::object
  :slots ())

(defmethod event_comm::EventHeartBeat
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

(setf (get event_comm::EventHeartBeat :md5sum-) "d41d8cd98f00b204e9800998ecf8427e")
(setf (get event_comm::EventHeartBeat :datatype-) "event_comm/EventHeartBeat")
(setf (get event_comm::EventHeartBeat :definition-)
      "
")



(provide :event_comm/EventHeartBeat "d41d8cd98f00b204e9800998ecf8427e")


