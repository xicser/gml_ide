;; Auto-generated. Do not edit!


(when (boundp 'osflock_test::IDCmd)
  (if (not (find-package "OSFLOCK_TEST"))
    (make-package "OSFLOCK_TEST"))
  (shadow 'IDCmd (find-package "OSFLOCK_TEST")))
(unless (find-package "OSFLOCK_TEST::IDCMD")
  (make-package "OSFLOCK_TEST::IDCMD"))

(in-package "ROS")
;;//! \htmlinclude IDCmd.msg.html


(defclass osflock_test::IDCmd
  :super ros::object
  :slots (_id _cmd ))

(defmethod osflock_test::IDCmd
  (:init
   (&key
    ((:id __id) 0)
    ((:cmd __cmd) "")
    )
   (send-super :init)
   (setq _id (round __id))
   (setq _cmd (string __cmd))
   self)
  (:id
   (&optional __id)
   (if __id (setq _id __id)) _id)
  (:cmd
   (&optional __cmd)
   (if __cmd (setq _cmd __cmd)) _cmd)
  (:serialization-length
   ()
   (+
    ;; int8 _id
    1
    ;; string _cmd
    4 (length _cmd)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int8 _id
       (write-byte _id s)
     ;; string _cmd
       (write-long (length _cmd) s) (princ _cmd s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int8 _id
     (setq _id (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _id 127) (setq _id (- _id 256)))
   ;; string _cmd
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _cmd (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get osflock_test::IDCmd :md5sum-) "8de13cc4a5bfcc15ab1cf03b69806e36")
(setf (get osflock_test::IDCmd :datatype-) "osflock_test/IDCmd")
(setf (get osflock_test::IDCmd :definition-)
      "int8 id # agent id
string cmd # agent command, include takeoff start land
")



(provide :osflock_test/IDCmd "8de13cc4a5bfcc15ab1cf03b69806e36")


