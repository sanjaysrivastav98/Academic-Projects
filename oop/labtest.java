import java.awt.event.*;

import javax.swing.*;

import java.awt.*;
import java.awt.geom.*;

// class implementing the icon
class CircleIcon implements Icon
{
	private double		radius;			// radius of the circle icon
	private int			X_position;		// x-position of circle icon
	private int			Y_position;		// y-position of circle icon
	// Constructor Method
	CircleIcon(double radius)
	{
		this.radius 		= 	radius;
		this.X_position 	= 	300;	// current x-position is 300
		this.Y_position 	= 	0;		// current y-position is 0
	}

	// Methods for getting icon height and width
	public int getIconWidth()			{	return (int)radius;   	}
	public int getIconHeight()			{	return (int)radius;   	}

	// Method for painting icon
	public void paintIcon(Component C,Graphics g, int x,int y)
	{
	Graphics2D g2 = (Graphics2D)g;
	Ellipse2D.Double circle = new Ellipse2D.Double(x+X_position,y+Y_position,radius,radius);
	g2.draw(circle);
	g2.setColor(Color.red);
	g2.fill(circle);
	}
	
	//    ADD ANY OTHER METHOD(s) THAT YOU THINK IS/ARE REQUIRED FOR THIS PROBLEM. DO NOT REMOVE
	//    THESE COMMENTS JUST WRITE YOUR CODE AFTER THESE COMMENTS
	public int getXPosition(){
		return X_position;
	}
	public void setIconWidth(double r){
		this.radius=r;
	}
	public void setXPosition(int x){
		this.X_position=x;
	}

}// End of class CircleIcon


//-----------------------------------------FOUR THREAD CLASSES -------------------------

class LeftThread extends Thread
{
						// COMPLETE THE CODE FOR THIS CLASS
	CircleIcon c;
	boolean suspendFlag=true;
	JFrame frame;
	LeftThread(JFrame frame,CircleIcon c,boolean s){
		this.frame=frame;
		this.c = c;
		this.suspendFlag=s;
	}
	
	public void mySuspend(){
		this.suspendFlag=true;
	}
	public void myResume(){
		synchronized(c){
			this.suspendFlag=false;
			c.notifyAll();
		}
	}
	public void run(){
		synchronized(c){
			try{
				while(suspendFlag){
					c.wait();
				}
				while(!suspendFlag){
					if(c.getXPosition()>=0){
						c.setXPosition(c.getXPosition()-1);
						Thread.sleep(10);
					}
					else{
						c.setXPosition(0);
					}
					frame.validate();
					frame.repaint();
					
				}
			}
			catch(Exception e){}
		}
		run();
	}
}

class RightThread extends Thread
{
						// COMPLETE THE CODE FOR THIS CLASS
	CircleIcon c;
	boolean suspendFlag=true;
	JFrame frame;
	RightThread(JFrame frame,CircleIcon c,boolean s){
		this.frame=frame;
		this.c = c;
		this.suspendFlag=s;
	}
	public void mySuspend(){
		this.suspendFlag=true;
	}
	public void myResume(){
		synchronized(c){
			this.suspendFlag=false;
			c.notifyAll();
		}
	}
	public void run(){
		synchronized(c){
			try{
				while(suspendFlag){
					c.wait();
				}
				while(!suspendFlag){
					if(c.getXPosition()<600-c.getIconWidth()){
						c.setXPosition(c.getXPosition()+1);
						Thread.sleep(10);
					}
					else{
						c.setXPosition(600-c.getIconWidth());
					}
					frame.validate();
					frame.repaint();
					
				}
			}
			catch(Exception e){}
		}
		run();
	}
}

class ScaleUpThread extends Thread
{
						// COMPLETE THE CODE FOR THIS CLASS
	CircleIcon c;
	boolean suspendFlag=true;
	JFrame frame;
	ScaleUpThread(JFrame frame,CircleIcon c,boolean s){
		this.frame=frame;
		this.c = c;
		this.suspendFlag=s;
	}
	public void mySuspend(){
		this.suspendFlag=true;
	}
	public void myResume(){
		synchronized(c){
			this.suspendFlag=false;
			c.notifyAll();
		}
	}
	public void run(){
		synchronized(c){
			try{
				while(suspendFlag){
					c.wait();
				}
				while(!suspendFlag){
					if(c.getIconWidth()<50){
						c.setIconWidth(c.getIconWidth()+1);
						Thread.sleep(10);
					}
					else{
						c.setIconWidth(50);
					}
					frame.validate();
					frame.repaint();
				}
			}
			catch(Exception e){}
		}
		run();
	}
}
class ScaleDownThread extends Thread
{
						// COMPLETE THE CODE FOR THIS CLASS
	CircleIcon c;
	boolean suspendFlag=true;
	JFrame frame;
	ScaleDownThread(JFrame frame,CircleIcon c,boolean s){
		this.frame=frame;
		this.c = c;
		this.suspendFlag=s;
	}
	public void mySuspend(){
		this.suspendFlag=true;
	}
	public void myResume(){
		synchronized(c){
			this.suspendFlag=false;
			c.notifyAll();
		}
	}
	public void run(){
		synchronized(c){
			try{
				while(suspendFlag){
					c.wait();
				}
				while(!suspendFlag){
					if(c.getIconWidth()>5){
						c.setIconWidth(c.getIconWidth()-1);
						Thread.sleep(10);
					}
					else{
						c.setIconWidth(5);
					}
					frame.validate();
					frame.repaint();
					
				}
			}
			catch(Exception e){}
		}
		run();
	}
}

//----------------------------------------THREAD CLASSES ENDS HERE------------------------




// Driver class
class OnlineMain
{
	// The following four boolean class variables can be used to determine whether the thread has started or not
	// While starting any thread just make the corresponding flag as  true. Initially no thread is started.
	public static boolean leftThreadStarted 		= false;	//leftThread not started initially
	public static boolean rightThreadStarted 		= false;	//rightThread not started initially
	public static boolean scaleUpThreadStarted 		= false;	//scaleUpThread not started initially
	public static boolean scaleDownThreadStarted 	= false;	//scaleDownThread not started initially

	// The following four boolean class variables can be used to determine which thread is currently running
	// Only one of the following 4 variables will be true at a time and rest other are false.
	// Initially no thread is running
	public static boolean leftThreadRunning 		= false;	//leftThread is not running initially
	public static boolean rightThreadRunning 		= false;	//rightThread is not running initially
	public static boolean scaleUpThreadRunning 		= false;	//scaleUpThread is not running initially
	public static boolean scaleDownThreadRunning 	= false;	//scaleDownThread is not running initially

	// Driver main() Method
	public static void main(String args[])
	{

		JFrame frame = new JFrame("Main Frame");	// original frame
		frame.setSize(600,600);						// size 600 * 600
		frame.setLayout(new BorderLayout());		// layout BorderLayout

		// Create a CircleIcon instance circleIcon with initial radius 10
		CircleIcon circleIcon = new CircleIcon(10);

		// Create a JLabel instance named iconLabel which can hold above circleIcon
		final JLabel iconLabel = new JLabel();
		iconLabel.setIcon(circleIcon);		// setting icon for iconLabel

		// Create a JPanel for holding iconLabel
		JPanel centrePanel = new JPanel(new BorderLayout());
		centrePanel.add(iconLabel,BorderLayout.CENTER);		// Adding iconLabel in the center of centrePanel

		// Create Buttons with labels as mentioned in the Question
		JButton leftButton 			= 	new JButton("LEFT");		// left button
		JButton rightButton 		= 	new JButton("RIGHT");		// right button
		JButton scaleUpButton 		= 	new JButton("SCALE UP");	// scaleUp button
		JButton scaleDownButton 	= 	new JButton("SCALE DOWN");	// scaleDown button
		JButton stopButton 			= 	new JButton("STOP");		// stop button

		// Create a buttonPanel for holding buttons
		JPanel buttonPanel		=	new JPanel();

		// Add buttons to buttonPanel
		buttonPanel.add(leftButton);
		buttonPanel.add(rightButton);
		buttonPanel.add(scaleUpButton);
		buttonPanel.add(scaleDownButton);
		buttonPanel.add(stopButton);


		// Add centrePanel to center of frame
		frame.add(centrePanel,BorderLayout.CENTER);

		// Add buttonPanel to south portion of frame
		frame.add(buttonPanel,BorderLayout.SOUTH);

		// Display Frame
		frame.setVisible(true);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);	// Default close operation

		//---------------------------------------- WRITE YOUR CODE FROM HERE---------------------------

		// Complete the following thread creating statement(s) after removing the comments

		 final LeftThread leftThread 				= 	new LeftThread(frame,circleIcon,!leftThreadRunning);
		 final RightThread rightThread 			= 	new RightThread(frame,circleIcon,!rightThreadRunning);
		 final ScaleUpThread scaleUpThread 		= 	new ScaleUpThread(frame,circleIcon,!scaleUpThreadRunning);
		 final ScaleDownThread scaleDownThread 	= 	new ScaleDownThread(frame,circleIcon,!scaleDownThreadRunning);
		 leftThread.start();
		 rightThread.start();
		 scaleUpThread.start();
		 scaleDownThread.start();
		 leftThreadStarted 		= true;
		 rightThreadStarted 	= true;
		 scaleUpThreadStarted	= true;
		 scaleDownThreadStarted = true;

		// WRITE JAVA CODE FOR ACTIONLISTENERS FOR VARIOUS BUTTONS. USE ONLY INNER CLASSES FOR THE SAME
		 leftButton.addActionListener(new ActionListener(){
			 public void actionPerformed(ActionEvent ae){
				 rightThread.mySuspend();rightThreadRunning=false;
				 scaleUpThread.mySuspend();scaleUpThreadRunning= false;
				 scaleDownThread.mySuspend();scaleDownThreadRunning= false;
				 if(leftThreadRunning){}
				 else{
					 leftThread.myResume();leftThreadRunning=true;
				 }
			 }
		 });
		 rightButton.addActionListener(new ActionListener(){
			 public void actionPerformed(ActionEvent ae){
				 leftThread.mySuspend();leftThreadRunning=false;
				 scaleUpThread.mySuspend();scaleUpThreadRunning= false;
				 scaleDownThread.mySuspend();scaleDownThreadRunning= false;
				 if(rightThreadRunning){}
				 else{
					 rightThread.myResume();rightThreadRunning=true;
					 }
				 
			 }
		 });
		 scaleUpButton.addActionListener(new ActionListener(){
			 public void actionPerformed(ActionEvent ae){
				 rightThread.mySuspend();rightThreadRunning=false;
				 leftThread.mySuspend();leftThreadRunning=false;
				 scaleDownThread.mySuspend();scaleDownThreadRunning= false;
				 if(scaleUpThreadRunning){}
				 else{
					 scaleUpThread.myResume();scaleUpThreadRunning=true;
					 }
			 }
		 });
		 scaleDownButton.addActionListener(new ActionListener(){
			 public void actionPerformed(ActionEvent ae){
				 rightThread.mySuspend();rightThreadRunning=false;
				 scaleUpThread.mySuspend();scaleUpThreadRunning= false;
				 leftThread.mySuspend();leftThreadRunning=false;
				 if(scaleDownThreadRunning){}
				 else{
					 scaleDownThread.myResume();scaleDownThreadRunning=true;
					 }
			 }
		 });
		 stopButton.addActionListener(new ActionListener(){
			 public void actionPerformed(ActionEvent ae){
				 rightThread.mySuspend();rightThreadRunning=false;
				 scaleUpThread.mySuspend();scaleUpThreadRunning= false;
				 scaleDownThread.mySuspend();scaleDownThreadRunning= false;
				 leftThread.mySuspend();leftThreadRunning=false;
			 }
		 });

	} // End of main() Method
}// End of class OnlineMain