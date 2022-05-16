package com.wang.TestMouseListener;

import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.ArrayList;
import java.util.Iterator;

public class TestMouseListener {
    public static void main(String[] args) {
        MyFrame frame = new MyFrame("画图");

    }
}
class MyFrame extends Frame{
    //画画需要画笔，需要监听鼠标当前的位置，这个集合用来存储点的位置
    ArrayList points;

    private class MyMouseListener extends MouseAdapter{
        @Override
        public void mousePressed(MouseEvent e) {
            // 每次鼠标点击的时候都会触发这个事件，在这个事件中获取调用这个事件的对象，也就是这个MyFrame
            MyFrame frame = (MyFrame) e.getSource();
            // 当我们点击的时候，就会在界面上产生一个点
            frame.addPaint(new Point(e.getX(), e.getY()));
            //
            frame.repaint();
        }
    }
    public MyFrame(String title){
        super(title);
        setBounds(200, 200, 400, 300);
        //存鼠标点击的点
        points = new ArrayList<>();

        setVisible(true);
        // 给MyFrame 添加一个鼠标的监听器，传入一个自己写的鼠标监听器
        this.addMouseListener(new MyMouseListener());
    }

    @Override
    public void paint(Graphics g) {
        //这个paint方法会检查points这个数组泪目有没有点，有的话就会画画，没有的画就不会画画，
        // 但是只执行一次，所以要在鼠标点击监听器中调用repaint方法在每次鼠标点击之后都重画
        Iterator iterator = points.iterator();
        while (iterator.hasNext()){
            Point point = (Point) iterator.next();// 调用next方法，迭代器会返回一个points中的对象并跳到下一个
            g.setColor(Color.BLUE);
            g.fillOval(point.x, point.y, 10, 10);
        }
    }

    public void addPaint(Point point){
        // 将产生的点加入这个points的数组中
        points.add(point);
    }


}