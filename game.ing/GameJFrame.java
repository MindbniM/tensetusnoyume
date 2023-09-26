package com.MindbniM.ui;

import javax.swing.*;

public class GameJFrame extends JFrame {
    public GameJFrame(){
        this.setSize(720,480);
        initimage();
        this.setVisible(true);
    }

    private  void initimage() {
        ImageIcon image=new ImageIcon("C:\\Users\\17713\\IdeaProjects\\game\\huanjie\\mmexport1695718070288.png");
        JLabel J=new JLabel(image);
        J.setBounds(0,0,108,108);
        this.getContentPane().add(J);
    }
}
