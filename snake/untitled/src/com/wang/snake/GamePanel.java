package com.wang.snake;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.Random;


public class GamePanel extends JPanel implements KeyListener, ActionListener {
    // 蛇前进的方向
    String fx;
    // 蛇的长度
    int length;
    // 蛇的坐标
    int[] snakeX = new int[600];
    int[] snakeY = new int[600];

    // 蛇前进的定时器
    Timer timer;

    // 食物参数
    int foodX;
    int foodY;

    // 随机数
    Random random = new Random();

    //玩家参数
    int score;
    boolean isFail;
    boolean isStart;
    boolean isPass;

    public GamePanel(){
        init();
        // 获取键盘的监听事件
        this.setFocusable(true);
        this.addKeyListener(this);
        timer = new javax.swing.Timer(100, this);
        timer.start();
    }

    public void init(){
        length = 3;
        snakeX[0] = 100;
        snakeY[0] = 100;
        snakeX[1] = 75;
        snakeY[1] = 100;
        snakeX[2] = 50;
        snakeY[2] = 100;
        fx = "R";
        isFail = false;
        isStart = false;
        isPass = false;
        foodX = 25 + 25 * random.nextInt(34);
        foodY = 75 + 25 * random.nextInt(24);

        score = 0;
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g); // 清屏
        this.setBackground(Color.WHITE);

        Data.header.paintIcon(this, g, 25, 11);
        // 画游戏区域
        g.fillRect(25, 75, 850, 600);

        switch (fx) { //根据方向绘制贪吃蛇头部
            case "U":
                Data.up.paintIcon(this, g, snakeX[0], snakeY[0]);
                break;
            case "D":
                Data.down.paintIcon(this, g, snakeX[0], snakeY[0]);
                break;
            case "L":
                Data.left.paintIcon(this, g, snakeX[0], snakeY[0]);
                break;
            case "R":
                Data.right.paintIcon(this, g, snakeX[0], snakeY[0]);
                break;
        }

        for(int i = 1; i < length; i++){
            Data.body.paintIcon(this, g, snakeX[i], snakeY[i]);
        }

        Data.food.paintIcon(this, g, foodX, foodY);

        g.setColor(Color.white);
        g.setFont(new Font("微软雅黑", Font.BOLD, 18));
        g.drawString("长度：" + length, 750, 35);
        g.drawString("分数：" + score, 750, 55);

        if(!isStart){
            g.setColor(Color.white);
            g.setFont(new Font("微软雅黑", Font.BOLD, 40));
            g.drawString("按下空格开始游戏", 300, 300);
        }

        if (isFail) {
            g.setColor(Color.RED);
            g.setFont(new Font("微软雅黑", Font.BOLD, 40));//设置字体
            g.drawString("游戏结束，按下空格重新开始游戏", 150, 300);
            g.drawString("长度为：" + length + "，分数为：" + score, 200, 350);
        }

        if (isPass) {
            g.setColor(Color.YELLOW);
            g.setFont(new Font("微软雅黑", Font.BOLD, 40));//设置字体
            g.drawString("游戏通关！", 350, 300);
        }
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        int delay = 100 - score / 5;
        timer.setDelay(delay);
        if(delay <= 20){
            isPass = true;
            repaint();
        }
        // 如果游戏处于开始状态并且没有结束或者通关就移动贪吃蛇
        if(isStart && !isFail && !isPass){
            for(int i = length - 1; i > 0; i--){
                snakeX[i] = snakeX[i - 1];
                snakeY[i] = snakeY[i - 1];
            }

            switch (fx) {
                case "R":
                    snakeX[0] = snakeX[0] + 25;//头部移动
                    //边界判断
                    if (snakeX[0] > 850) {
                        isFail = true;
                    }
                    break;
                case "L":
                    snakeX[0] = snakeX[0] - 25;//头部移动
                    //边界判断
                    if (snakeX[0] < 25) {
                        isFail = true;
                    }
                    break;
                case "U":
                    snakeY[0] = snakeY[0] - 25;//头部移动
                    //边界判断
                    if (snakeY[0] < 75) {
                        isFail = true;
                    }
                    break;
                case "D":
                    snakeY[0] = snakeY[0] + 25;//头部移动
                    //边界判断
                    if (snakeY[0] > 650) {
                        isFail = true;
                    }
                    break;
            }

            // 如果小蛇的头和食物坐标重合就是吃到了食物
            if(snakeX[0] == foodX && snakeY[0] == foodY){
                length++;
                score += 10;
                foodX = 25 + 25 * random.nextInt(34);
                foodY = 75 + 25 * random.nextInt(24);
            }
            for(int i = 1; i < length; i++){
                if(snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i]){
                    isFail = true;
                    break;
                }
            }
            repaint();
        }
    }
    @Override
    public void keyPressed(KeyEvent e) {
        int keyCode = e.getKeyCode();
        if(keyCode == KeyEvent.VK_SPACE){
            if(isFail){
                init();
            }else{
                isStart = !isStart;
                repaint();
            }
        }
        if (keyCode == KeyEvent.VK_UP) {
            fx = "U";
        } else if (keyCode == KeyEvent.VK_DOWN) {
            fx = "D";
        } else if (keyCode == KeyEvent.VK_LEFT) {
            fx = "L";
        } else if (keyCode == KeyEvent.VK_RIGHT) {
            fx = "R";
        }
    }

    @Override
    public void keyTyped(KeyEvent e) {

    }
    @Override
    public void keyReleased(KeyEvent e) {

    }
}
