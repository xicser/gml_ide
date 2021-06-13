;; Auto-generated. Do not edit!


(when (boundp 'vsform_test::Goal)
  (if (not (find-package "VSFORM_TEST"))
    (make-package "VSFORM_TEST"))
  (shadow 'Goal (find-package "VSFORM_TEST")))
(unless (find-package "VSFORM_TEST::GOAL")
  (make-package "VSFORM_TEST::GOAL"))

(in-package "ROS")
;;//! \htmlinclude Goal.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass vsform_test::Goal
  :super ros::object
  :slots (_frame_pos _frame_vel _path_width ))

(defmethod vsform_test::Goal
  (:init
   (&key
    ((:frame_pos __frame_pos) (instance geometry_msgs::Point32 :init))
    ((:frame_vel __frame_vel) (instance geometry_msgs::Point32 :init))
    ((:path_width __path_width) 0.0)
    )
   (send-super :init)
   (setq _frame_pos __frame_pos)
   (setq _frame_vel __frame_vel)
   (setq _path_width (float __path_width))
   self)
  (:frame_pos
   (&rest __frame_pos)
   (if (keywordp (car __frame_pos))
       (send* _frame_pos __frame_pos)
     (progn
       (if __frame_pos (setq _frame_pos (car __frame_pos)))
       _frame_pos)))
  (:frame_vel
   (&rest __frame_vel)
   (if (keywordp (car __frame_vel))
       (send* _frame_vel __frame_vel)
     (progn
       (if __frame_vel (setq _frame_vel (car __frame_vel)))
       _frame_vel)))
  (:path_width
   (&optional __path_width)
   (if __path_width (setq _path_width __path_width)) _path_width)
  (:serialization-length
   ()
   (+
    ;; geometry_msgs/Point32 _frame_pos
    (send _frame_pos :serialization-length)
    ;; geometry_msgs/Point32 _frame_vel
    (send _frame_vel :serialization-length)
    ;; float32 _path_width
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; geometry_msgs/Point32 _frame_pos
       (send _frame_pos :serialize s)
     ;; geometry_msgs/Point32 _frame_vel
       (send _frame_vel :serialize s)
     ;; float32 _path_width
       (sys::poke _path_width (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; geometry_msgs/Point32 _frame_pos
     (send _frame_pos :deserialize buf ptr-) (incf ptr- (send _frame_pos :serialization-length))
   ;; geometry_msgs/Point32 _frame_vel
     (send _frame_vel :deserialize buf ptr-) (incf ptr- (send _frame_vel :serialization-length))
   ;; float32 _path_width
     (setq _path_width (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get vsform_test::Goal :md5sum-) "b0c8263c41fcbdd38a6148d2ecdf8e38")
(setf (get vsform_test::Goal :datatype-) "vsform_test/Goal")
(setf (get vsform_test::Goal :definition-)
      "geometry_msgs/Point32 frame_pos # frame position
geometry_msgs/Point32 frame_vel # frame velocity
float32 path_width # path width
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



(provide :vsform_test/Goal "b0c8263c41fcbdd38a6148d2ecdf8e38")


