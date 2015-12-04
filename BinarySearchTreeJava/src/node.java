/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Kenneth
 */
public class node {
    //The information stored in the node
    public int data;
    //pointers
    public node left;
    public node right;
    //constructor
    public node(int data){
        this.data = data;
        this.left = null;
        this.right = null;
    }
}
