;; Auto-generated. Do not edit!


(when (boundp 'ros_robot::Active)
  (if (not (find-package "ROS_ROBOT"))
    (make-package "ROS_ROBOT"))
  (shadow 'Active (find-package "ROS_ROBOT")))
(unless (find-package "ROS_ROBOT::ACTIVE")
  (make-package "ROS_ROBOT::ACTIVE"))

(in-package "ROS")
;;//! \htmlinclude Active.msg.html


(defclass ros_robot::Active
  :super ros::object
  :slots (_direction _speed _ptz ))

(defmethod ros_robot::Active
  (:init
   (&key
    ((:direction __direction) 0)
    ((:speed __speed) 0)
    ((:ptz __ptz) 0)
    )
   (send-super :init)
   (setq _direction (round __direction))
   (setq _speed (round __speed))
   (setq _ptz (round __ptz))
   self)
  (:direction
   (&optional __direction)
   (if __direction (setq _direction __direction)) _direction)
  (:speed
   (&optional __speed)
   (if __speed (setq _speed __speed)) _speed)
  (:ptz
   (&optional __ptz)
   (if __ptz (setq _ptz __ptz)) _ptz)
  (:serialization-length
   ()
   (+
    ;; int8 _direction
    1
    ;; int8 _speed
    1
    ;; int8 _ptz
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int8 _direction
       (write-byte _direction s)
     ;; int8 _speed
       (write-byte _speed s)
     ;; int8 _ptz
       (write-byte _ptz s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int8 _direction
     (setq _direction (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _direction 127) (setq _direction (- _direction 256)))
   ;; int8 _speed
     (setq _speed (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _speed 127) (setq _speed (- _speed 256)))
   ;; int8 _ptz
     (setq _ptz (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _ptz 127) (setq _ptz (- _ptz 256)))
   ;;
   self)
  )

(setf (get ros_robot::Active :md5sum-) "f804e429aeb8f3511a613f05f7284a12")
(setf (get ros_robot::Active :datatype-) "ros_robot/Active")
(setf (get ros_robot::Active :definition-)
      "int8 direction
int8 speed
int8 ptz

")



(provide :ros_robot/Active "f804e429aeb8f3511a613f05f7284a12")


