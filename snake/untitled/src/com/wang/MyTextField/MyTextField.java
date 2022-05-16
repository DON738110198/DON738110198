package com.wang.MyTextField;


import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MyTextField {
    public static void main(String[] args) {
        new MyFrame();
    }
}

class MyFrame extends Frame{
    public MyFrame(){
        TextField textField = new TextField();
        add(textField);

        // 监听这个文本框输入的文字
        MyActionListener2 myActionListener2 = new MyActionListener2();
        // 按下enter 就会触发这个输入框的事件
        textField.addActionListener(myActionListener2);

        textField.setEchoChar('*');

        setVisible(true);
        pack();
    }

}

class MyActionListener2 implements ActionListener{
    @Override
    public void actionPerformed(ActionEvent e) {
        TextField field = (TextField) e.getSource(); // 获得一些资源，返回的一个对象
        System.out.println(field.getText().toString()); // 获得输入框的文本
        field.setText("");
    }
}
