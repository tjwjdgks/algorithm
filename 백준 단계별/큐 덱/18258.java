import java.io.*;
import java.util.Scanner;
import java.util.StringTokenizer;

class Node{
    private int data;
    Node next;
    public Node(int data){
        this.data = data;
        next = null;
    }
    public int getData() {
        return data;
    }
    public void setData(int a){
        this.data = a;
    }
}
class Queue{
    int size;
    Node head;
    Node tail;
    public Queue() {
        size = 0;
        head = null;
        tail = null;
    }
    public void push(int data){
        Node temp = new Node(data);
        if(size == 0){
            head = temp;
            tail = temp;
        }
        else{
            tail.next = temp;
            tail = temp;
        }
        size +=1;
    }
    public int pop(){
        if(size == 0){
            return -1;
        }
        else{
            int num = head.getData();
            Node temp = head;
            head = temp.next;
            temp.next = null;
            temp. setData(0);
            size -=1;
            return num;
        }
    }
    public int getSize(){
        return this.size;
    }
    public int isEmpty(){
        if(size == 0)
            return 1;
        else
            return 0;
    }
    public int front(){
        if(size ==0)
            return -1;
        else
            return head.getData();
    }
    public int back(){
        if(size ==0)
            return -1;
        else
            return tail.getData();
    }
}
public class Main {
    public static void main(String args[]) throws IOException{
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        int cases = Integer.parseInt(bufferedReader.readLine());
        StringTokenizer st;
        StringBuffer sb = new StringBuffer();
        Queue q = new Queue();
        for(int i=0; i<cases;i++){
            st = new StringTokenizer(bufferedReader.readLine());
            String command = st.nextToken();
            if(command.equals("push")){
                int num = Integer.parseInt(st.nextToken());
                q.push(num);
            }
            else{
                switch (command){
                    case "pop" :
                        sb.append(q.pop()+"\n");
                        break;
                    case "size" :
                        sb.append(q.getSize()+"\n");
                        break;
                    case "empty" :
                        sb.append(q.isEmpty()+"\n");
                        break;
                    case "front" :
                        sb.append(q.front()+"\n");
                        break;
                    case "back" :
                        sb.append(q.back()+"\n");
                        break;
                }

            }
        }
        System.out.println(sb.toString());
    }
}
