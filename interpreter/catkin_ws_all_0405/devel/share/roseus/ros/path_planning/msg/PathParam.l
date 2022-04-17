;; Auto-generated. Do not edit!


(when (boundp 'path_planning::PathParam)
  (if (not (find-package "PATH_PLANNING"))
    (make-package "PATH_PLANNING"))
  (shadow 'PathParam (find-package "PATH_PLANNING")))
(unless (find-package "PATH_PLANNING::PATHPARAM")
  (make-package "PATH_PLANNING::PATHPARAM"))

(in-package "ROS")
;;//! \htmlinclude PathParam.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass path_planning::PathParam
  :super ros::object
  :slots (_start _goal ))

(defmethod path_planning::PathParam
  (:init
   (&key
    ((:start __start) (instance geometry_msgs::Point :init))
    ((:goal __goal) (instance geometry_msgs::Point :init))
    )
   (send-super :init)
   (setq _start __start)
   (setq _goal __goal)
   self)
  (:start
   (&rest __start)
   (if (keywordp (car __start))
       (send* _start __start)
     (progn
       (if __start (setq _start (car __start)))
       _start)))
  (:goal
   (&rest __goal)
   (if (keywordp (car __goal))
       (send* _goal __goal)
     (progn
       (if __goal (setq _goal (car __goal)))
       _goal)))
  (:serialization-length
   ()
   (+
    ;; geometry_msgs/Point _start
    (send _start :serialization-length)
    ;; geometry_msgs/Point _goal
    (send _goal :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; geometry_msgs/Point _start
       (send _start :serialize s)
     ;; geometry_msgs/Point _goal
       (send _goal :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; geometry_msgs/Point _start
     (send _start :deserialize buf ptr-) (incf ptr- (send _start :serialization-length))
   ;; geometry_msgs/Point _goal
     (send _goal :deserialize buf ptr-) (incf ptr- (send _goal :serialization-length))
   ;;
   self)
  )

(setf (get path_planning::PathParam :md5sum-) "efcee77d261910bec0163bff1fcbe065")
(setf (get path_planning::PathParam :datatype-) "path_planning/PathParam")
(setf (get path_planning::PathParam :definition-)
      "geometry_msgs/Point start
geometry_msgs/Point goal
================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

")



(provide :path_planning/PathParam "efcee77d261910bec0163bff1fcbe065")


