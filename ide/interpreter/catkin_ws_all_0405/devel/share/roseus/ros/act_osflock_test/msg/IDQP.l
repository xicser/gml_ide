;; Auto-generated. Do not edit!


(when (boundp 'act_osflock_test::IDQP)
  (if (not (find-package "ACT_OSFLOCK_TEST"))
    (make-package "ACT_OSFLOCK_TEST"))
  (shadow 'IDQP (find-package "ACT_OSFLOCK_TEST")))
(unless (find-package "ACT_OSFLOCK_TEST::IDQP")
  (make-package "ACT_OSFLOCK_TEST::IDQP"))

(in-package "ROS")
;;//! \htmlinclude IDQP.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass act_osflock_test::IDQP
  :super ros::object
  :slots (_id _q _p ))

(defmethod act_osflock_test::IDQP
  (:init
   (&key
    ((:id __id) 0)
    ((:q __q) (instance geometry_msgs::Point32 :init))
    ((:p __p) (instance geometry_msgs::Point32 :init))
    )
   (send-super :init)
   (setq _id (round __id))
   (setq _q __q)
   (setq _p __p)
   self)
  (:id
   (&optional __id)
   (if __id (setq _id __id)) _id)
  (:q
   (&rest __q)
   (if (keywordp (car __q))
       (send* _q __q)
     (progn
       (if __q (setq _q (car __q)))
       _q)))
  (:p
   (&rest __p)
   (if (keywordp (car __p))
       (send* _p __p)
     (progn
       (if __p (setq _p (car __p)))
       _p)))
  (:serialization-length
   ()
   (+
    ;; int8 _id
    1
    ;; geometry_msgs/Point32 _q
    (send _q :serialization-length)
    ;; geometry_msgs/Point32 _p
    (send _p :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int8 _id
       (write-byte _id s)
     ;; geometry_msgs/Point32 _q
       (send _q :serialize s)
     ;; geometry_msgs/Point32 _p
       (send _p :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int8 _id
     (setq _id (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _id 127) (setq _id (- _id 256)))
   ;; geometry_msgs/Point32 _q
     (send _q :deserialize buf ptr-) (incf ptr- (send _q :serialization-length))
   ;; geometry_msgs/Point32 _p
     (send _p :deserialize buf ptr-) (incf ptr- (send _p :serialization-length))
   ;;
   self)
  )

(setf (get act_osflock_test::IDQP :md5sum-) "de73cd8cc01a3a407b0a10781a1dd6a4")
(setf (get act_osflock_test::IDQP :datatype-) "act_osflock_test/IDQP")
(setf (get act_osflock_test::IDQP :definition-)
      "int8 id # agent id
geometry_msgs/Point32 q # agent position
geometry_msgs/Point32 p # agent velocity

================================================================================
MSG: geometry_msgs/Point32
# This contains the position of a point in free space(with 32 bits of precision).
# It is recommeded to use Point wherever possible instead of Point32.  
# 
# This recommendation is to promote interoperability.  
#
# This message is designed to take up less space when sending
# lots of points at once, as in the case of a PointCloud.  

float32 x
float32 y
float32 z
")



(provide :act_osflock_test/IDQP "de73cd8cc01a3a407b0a10781a1dd6a4")


