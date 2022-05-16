package com.wang.TestMouseListener;

import javax.xml.namespace.QName;
import java.sql.Array;
import java.util.*;

public class Obj{
    public static void main(String[] args) {
        HashSet hashSet = new HashSet();
        hashSet.add(new Employee("王浩", 100, new MyDate(2003, 2, 5)));
        hashSet.add(new Employee("王浩", 200, new MyDate(2003, 2, 5)));
        System.out.println("hashSet = " + hashSet);
        System.out.println("王浩爱丽丝多煎熬老师大力啊大苏打阿萨阿斯顿 艾顿阿萨dasdadasdasd");
    }
}
class Employee{
    private String name;
    private int sal;
    private MyDate birthday;

    public Employee(String name, int sal, MyDate birthday) {
        this.name = name;
        this.sal = sal;
        this.birthday = birthday;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Employee employee = (Employee) o;
        return Objects.equals(name, employee.name) && Objects.equals(birthday, employee.birthday);
    }

    @Override
    public int hashCode() {
        return Objects.hash(name, birthday);
    }

    @Override
    public String toString() {
        return "Employee{" +
                "name='" + name + '\'' +
                ", sal=" + sal +
                ", birthday=" + birthday +
                '}';
    }
}

class MyDate{
    int year;
    int month;
    int day;

    public MyDate(int year, int month, int day) {
        this.year = year;
        this.month = month;
        this.day = day;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        MyDate myDate = (MyDate) o;
        return year == myDate.year && month == myDate.month && day == myDate.day;
    }

    @Override
    public int hashCode() {
        return Objects.hash(year, month, day);
    }
}
