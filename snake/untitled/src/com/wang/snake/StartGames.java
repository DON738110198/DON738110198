package com.wang.snake;

import javax.swing.*;
import java.awt.*;

public class StartGames {
    public static void main(String[] args) {
        // 绘制静态窗口
        JFrame frame = new JFrame("贪吃蛇");
        frame.setBounds(10, 10, 900, 720);
        frame.setResizable(false);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // 将面板 Jpanel 加入到 frame中
        frame.add(new GamePanel());

        frame.setVisible(true);
    }
}
