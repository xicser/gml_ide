;; Auto-generated. Do not edit!


(when (boundp 'sml_dyn::Event)
  (if (not (find-package "SML_DYN"))
    (make-package "SML_DYN"))
  (shadow 'Event (find-package "SML_DYN")))
(unless (find-package "SML_DYN::EVENT")
  (make-package "SML_DYN::EVENT"))

(in-package "ROS")
;;//! \htmlinclude Event.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass sml_dyn::Event
  :super ros::object
  :slots (_id _name _prior _time _pos _data ))

(defmethod sml_dyn::Event
  (:init
   (&key
    ((:id __id) 0)
    ((:name __name) "")
    ((:prior __prior) 0)
    ((:time __time) (instance ros::time :init))
    ((:pos __pos) (instance geometry_msgs::Point :init))
    ((:data __data) (instance geometry_msgs::Point :init))
    )
   (send-super :init)
   (setq _id (round __id))
   (setq _name (string __name))
   (setq _prior (round __prior))
   (setq _time __time)
   (setq _pos __pos)
   (setq _data __data)
   self)
  (:id
   (&optional __id)
   (if __id (setq _id __id)) _id)
  (:name
   (&optional __name)
   (if __name (setq _name __name)) _name)
  (:prior
   (&optional __prior)
   (if __prior (setq _prior __prior)) _prior)
  (:time
   (&optional __time)
   (if __time (setq _time __time)) _time)
  (:pos
   (&rest __pos)
   (if (keywordp (car __pos))
       (send* _pos __pos)
     (progn
       (if __pos (setq _pos (car __pos)))
       _pos)))
  (:data
   (&rest __data)
   (if (keywordp (car __data))
       (send* _data __data)
     (progn
       (if __data (setq _data (car __data)))
       _data)))
  (:serialization-length
   ()
   (+
    ;; uint64 _id
    8
    ;; string _name
    4 (length _name)
    ;; uint8 _prior
    1
    ;; time _time
    8
    ;; geometry_msgs/Point _pos
    (send _pos :serialization-length)
    ;; geometry_msgs/Point _data
    (send _data :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint64 _id
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _id (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _id) (= (length (_id . bv)) 2)) ;; bignum
              (write-long (ash (elt (_id . bv) 0) 0) s)
              (write-long (ash (elt (_id . bv) 1) -1) s))
             ((and (class _id) (= (length (_id . bv)) 1)) ;; big1
              (write-long (elt (_id . bv) 0) s)
              (write-long (if (>= _id 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _id s)(write-long (if (>= _id 0) 0 #xffffffff) s)))
     ;; string _name
       (write-long (length _name) s) (princ _name s)
     ;; uint8 _prior
       (write-byte _prior s)
     ;; time _time
       (write-long (send _time :sec) s) (write-long (send _time :nsec) s)
     ;; geometry_msgs/Point _pos
       (send _pos :serialize s)
     ;; geometry_msgs/Point _data
       (send _data :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint64 _id
     
#+(or :alpha :irix6 :x86_64)
      (setf _id (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _id (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; string _name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; uint8 _prior
     (setq _prior (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; time _time
     (send _time :sec (sys::peek buf ptr- :integer)) (incf ptr- 4)  (send _time :nsec (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; geometry_msgs/Point _pos
     (send _pos :deserialize buf ptr-) (incf ptr- (send _pos :serialization-length))
   ;; geometry_msgs/Point _data
     (send _data :deserialize buf ptr-) (incf ptr- (send _data :serialization-length))
   ;;
   self)
  )

(setf (get sml_dyn::Event :md5sum-) "22829605e857c5733b3d0b8eab5f82ce")
(setf (get sml_dyn::Event :datatype-) "sml_dyn/Event")
(setf (get sml_dyn::Event :definition-)
      "uint64 id                  # 事件的标识
string name                # 事件的名字
uint8 prior                # 事件的优先级 默认为0 越大越优先
time time                  # 事件的时间
geometry_msgs/Point pos    # 事件的位置
geometry_msgs/Point data   # 事件传输的数据
================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

")



(provide :sml_dyn/Event "22829605e857c5733b3d0b8eab5f82ce")


