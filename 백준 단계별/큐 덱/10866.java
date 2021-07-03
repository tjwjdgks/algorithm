import java.io.*;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;

class Node{
    private int data;
    Node next;
    Node pre;
    public Node(int data){
        this.data = data;
        next= null;
        pre = null;
    }
    public int getData() {
        return data;
    }
}
class Deque{
    Node head;
    Node tail;
    int size;
    public Deque(){
        head = null;
        tail = null;
        size = 0;
    }
    public void push_front(int data){
        Node tempN = new Node(data);
        if(IsEmpty() ==1){
            head = tempN;
            tail = tempN;
        }
        else{
            tempN.pre = head.pre;
            tempN.next = head;
            head.pre = tempN;
            head = tempN;
        }
        size +=1;
    }
    public void push_back(int data){
        Node tempN = new Node(data);
        if(IsEmpty() == 1){
            head = tempN;
            tail = tempN;
        }
        else{
            tempN.pre = tail;
            tempN.next = tail.next;
            tail.next = tempN;
            tail = tempN;
        }
        size+=1;
    }
    public int pop_front(){
        if(IsEmpty() == 1) return -1;
        else{
            int num = head.getData();
            head = head.next;
            if(head == null) tail = null;
            else head.pre = null;
            size -=1;
            return num;
        }
    }
    public int pop_back(){
        if(IsEmpty() == 1) return -1;
        else{
            int num = tail.getData();
            tail = tail.pre;
            if(tail == null)
                head = null;
            else
                tail.next = null;
            size -=1;
            return num;
        }
    }
    public int getSize(){
        return this.size;
    }
    public int IsEmpty(){
        if(size == 0) return 1;
        else return 0;
    }
    public int front(){
        if(IsEmpty() == 1)
            return -1;
        else return head.getData();
    }
    public int back(){
        if(IsEmpty() == 1)
            return -1;
        return tail.getData();
    }
}
public class Main {
    public static void main(String args[]) throws IOException{
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        int cases = Integer.parseInt(bufferedReader.readLine());
        StringTokenizer st;
        Deque deque = new Deque();
        StringBuffer sb = new StringBuffer();
        for(int i=0; i<cases;i++){
            st = new StringTokenizer(bufferedReader.readLine());
            String command = st.nextToken();
            if(command.equals("push_back")){
                int num = Integer.parseInt(st.nextToken());
                deque.push_back(num);
            }
            else if(command.equals("push_front")){
                int num = Integer.parseInt(st.nextToken());
                deque.push_front(num);
            }
            else{
                switch (command){
                    case "pop_front":
                        sb.append(deque.pop_front()+"\n");
                        break;
                    case "pop_back":
                        sb.append(deque.pop_back()+"\n");
                        break;
                    case "size":
                        sb.append(deque.getSize()+"\n");
                        break;
                    case "empty":
                        sb.append(deque.IsEmpty()+"\n");
                        break;
                    case "front":
                        sb.append(deque.front()+"\n");
                        break;
                    case "back":
                        sb.append(deque.back()+"\n");
                }
            }
        }
        System.out.println(sb.toString());
    }
}
