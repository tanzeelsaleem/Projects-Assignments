package LMS_DB;
import javax.swing.*;
import javax.swing.border.*;
import java.awt.*;
import java.awt.event.*;

public class searchMember extends JFrame implements ActionListener{
    JTextField snamet;
    String staffId,n;
    searchMember(String id,String n){
    	staffId = id;
    	this.n=n;
        String blue = "#3566b5";

        JPanel back = new JPanel();
        back.setLayout(new GridLayout());
        back.setBounds(5,18,60,30);
        JButton bbtn = new JButton("Back");
        bbtn.setBackground(Color.decode(blue));
        bbtn.setForeground(Color.white);
        bbtn.setFont(new Font("Times New Roman", Font.PLAIN, 12));
        bbtn.addActionListener(this);
        back.add(bbtn);
        
        JPanel p1 = new JPanel();
        p1.setLayout(new GridLayout());
        p1.setBounds(70,10,650,50);
        JLabel label = new JLabel("DRSM LIBRARY MANAGEMENT SYSTEM");
        label.setForeground(Color.decode(blue));
        label.setFont(new Font("Times New Roman",Font.BOLD,32));
        p1.add(label);

        JPanel logged = new JPanel();
        logged .setLayout(new GridLayout());
        logged .setBounds(650,12,220,50);
        JLabel name = new JLabel(n);
        name.setForeground(Color.BLACK);
        name.setHorizontalAlignment(SwingConstants.RIGHT);
        name.setFont(new Font("Calibri",Font.BOLD,20));
        logged.add(name);

        JButton logout = new JButton("Logout");
        logout.setBackground(Color.decode(blue));
        logout.setForeground(Color.white);
        logout.setFont(new Font("Times New Roman", Font.PLAIN, 15));
        logout.addActionListener(this);

        JPanel p2 = new JPanel();
        p2.setBounds(880,18,80,30);
        p2.setLayout(new GridLayout());
        p2.add(logout);

        JPanel p3 = new JPanel();
        p3.setLayout(new GridLayout());
        p3.setBounds(0,100,1000,50);
        JLabel tile = new JLabel("Search Member");
        tile.setForeground(Color.BLACK);
        tile.setHorizontalAlignment(SwingConstants.CENTER);
        tile.setFont(new Font("Times New Roman",Font.BOLD,25));
        p3.add(tile);

        JLabel sname = new JLabel("Member Username");
        sname.setFont(new Font("Times New Roman",Font.PLAIN,20));
        sname.setHorizontalAlignment(SwingConstants.RIGHT);
        snamet = new JTextField();
        snamet.setFont(new Font("Times New Roman", Font.PLAIN, 20));
        
        JPanel p4 = new JPanel();
        p4.setLayout(new GridLayout(1,2,10,10));
        p4.setBounds(50,170,600,40);
        p4.add(sname);
        p4.add(snamet);
        
        JButton search = new JButton("Search");
        search.setBackground(Color.decode(blue));
        search.setForeground(Color.white);
        search.setFont(new Font("Times New Roman", Font.PLAIN, 20));
        search.addActionListener(this);

        JPanel p5 = new JPanel();
        p5.setBounds(450,250,90,40);
        p5.setLayout(new GridLayout());
        p5.add(search);



        setTitle("DRSM LMS");
        setSize(1000,600);
        setVisible(true);
        setLayout(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        add(back);
        add(p1);
        add(logged);
        add(p2);
        add(p3);
        add(p4);
        add(p5);
    }

    @Override
	public void actionPerformed(ActionEvent e){
        JButton b = (JButton)e.getSource();
        String btn = b.getText();
        if(btn=="Back") {
        	dispose();
        	new staffUI(staffId,n);
        }
        if(btn=="Search") {
        	String find =snamet.getText();
        	dispose();
        	new showmem(find, staffId,n);
        }
        if(btn =="Logout"){
            dispose();
			new home();
        }
    }
    public static void main(String[] args) {
//        searchMember obj = new searchMember();
    }
}
