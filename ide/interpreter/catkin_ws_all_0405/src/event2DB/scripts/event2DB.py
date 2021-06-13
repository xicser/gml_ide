#!/usr/bin/env python3
# -*- coding:utf-8 -*-


import pymysql
import rospy
import time
from event_comm.msg import EventDynamic
from event_syn.msg import EventSynergy


table_suffix = None


def init():
    db = pymysql.connect("localhost", "root", "mysql123",
                         "micro_embedded_engine")
    cursor = db.cursor()
    CREATE_SQL = """CREATE TABLE IF NOT EXISTS `events%s` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `seq` int(11) DEFAULT NULL,
  `stamp` varchar(45)  DEFAULT NULL,
  `eventID` varchar(45) DEFAULT NULL,
  `source` varchar(45) DEFAULT NULL,
  `begintime` varchar(45)  DEFAULT NULL,
  `endtime` varchar(45)  DEFAULT NULL,
  `eventType` varchar(45) DEFAULT NULL,
  `eventName` varchar(45) DEFAULT NULL,
  `contentType` varchar(45) DEFAULT NULL,
  `contentInfo` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
""" % table_suffix
    cursor.execute(CREATE_SQL)
    db.commit()

    print("Table created successfully")

    filename = 'event.txt'
    with open(filename, 'w') as file_object:
        file_object.write(table_suffix)


    db.close()


def get_table_suffix():
    return time.strftime("%Y%m%d%H%M", time.localtime())


def insert_data(data):
    print(data)
    conn = pymysql.connect("localhost", "root", "mysql123",
                         "micro_embedded_engine")
    # INSERT_SQL = """ insert into "eventCCps507
    c = conn.cursor()
    # c.execute(INSERT_SQL, data)s%s" (seq,stamp,eventID,source,begintime,endtime,eventType,eventName,contentType,contentInfo) values(?, ?, ?, ?, ?, ?, ?, ?, ?, ?)""" % table_suffix
    INSERT_SQL = """ insert into events%s (seq,stamp,eventID,source,begintime,endtime,eventType,eventName,contentType,contentInfo) values('%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s')""" % (table_suffix,*data)
    print(INSERT_SQL)
    c.execute(INSERT_SQL)
    conn.commit()
    conn.close()
    print("Insert successfully")


def event_syn_callback(msg):
    # print(type(msg.synergyObject))
    temp = ','.join(msg.synergyObject) if isinstance(msg.synergyObject,list) else msg.synergyObject
    data = (msg.base.ID, msg.base.begintime.to_sec(), msg.base.ID, msg.base.source, msg.base.begintime.to_sec(),
            msg.base.endtime.to_sec(), "Collaborative", msg.synergyEvent, msg.synergyType, temp)
    insert_data(data)


def event_dynamic_callback(msg):
    data = (msg.base.header.seq, msg.base.header.stamp.to_sec(), msg.base.eventID, msg.base.source, msg.base.begintime.to_sec(),
            msg.base.endtime.to_sec(), "Dynamic", msg.dynamicEventName, msg.dynamicType, msg.dynamicInfo)
    insert_data(data)


def save_events():
    global table_suffix
    table_suffix = get_table_suffix()
    print("table_suffix:", table_suffix)
    init()
    print('init databse ok')
    rospy.init_node('save_uav_events', anonymous=True)
    rospy.Subscriber('/event_syn', EventSynergy, event_syn_callback)
    rospy.Subscriber('/event_dynamic', EventDynamic, event_dynamic_callback)
    rospy.spin()


if __name__ == "__main__":
    try:
        save_events()
    except rospy.ROSInterruptException:
        pass
