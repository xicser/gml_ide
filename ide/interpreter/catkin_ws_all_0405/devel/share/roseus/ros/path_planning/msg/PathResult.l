;; Auto-generated. Do not edit!


(when (boundp 'path_planning::PathResult)
  (if (not (find-package "PATH_PLANNING"))
    (make-package "PATH_PLANNING"))
  (shadow 'PathResult (find-package "PATH_PLANNING")))
(unless (find-package "PATH_PLANNING::PATHRESULT")
  (make-package "PATH_PLANNING::PATHRESULT"))

(in-package "ROS")
;;//! \htmlinclude PathResult.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass path_planning::PathResult
  :super ros::object
  :slots (_result ))

(defmethod path_planning::PathResult
  (:init
   (&key
    ((:result __result) (let (r) (dotimes (i 0) (push (instance geometry_msgs::Point :init) r)) r))
    )
   (send-super :init)
   (setq _result __result)
   self)
  (:result
   (&rest __result)
   (if (keywordp (car __result))
       (send* _result __result)
     (progn
       (if __result (setq _result (car __result)))
       _result)))
  (:serialization-length
   ()
   (+
    ;; geometry_msgs/Point[] _result
    (apply #'+ (send-all _result :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; geometry_msgs/Point[] _result
     (write-long (length _result) s)
     (dolist (elem _result)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; geometry_msgs/Point[] _result
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _result (let (r) (dotimes (i n) (push (instance geometry_msgs::Point :init) r)) r))
     (dolist (elem- _result)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get path_planning::PathResult :md5sum-) "5ac55cb602cab21c0a526eb965fe531a")
(setf (get path_planning::PathResult :datatype-) "path_planning/PathResult")
(setf (get path_planning::PathResult :definition-)
      "geometry_msgs/Point[] result
================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

")



(provide :path_planning/PathResult "5ac55cb602cab21c0a526eb965fe531a")


