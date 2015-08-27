/*
www.cslearner.com
This is a C# linked list based heavily off a pluralsight course titled "Algorithms and Data Structures - Part 1" by Robert Horvick
 */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LinkedListCSharp
{
    //A linked list collection capable of basic operations such as Add, Remove, Find, and Enumerate
    public class LinkedList<T>:System.Collections.Generic.ICollection<T>
    {
        //First node in the list or null if empty
        public LinkedListNode<T> Head
        {
            get;
            private set;
        }

        //The last node in the list or null if empty
        public LinkedListNode<T> Tail
        {
            get;
            private set;
        }

        #region Add
        //Adds the specified value to the start of the linked list
        public void AddFirst(T value)
        {
            AddFirst(new LinkedListNode<T>(value));
        }

        //Adds the specified nodes to the start of the linked list
        public void AddFirst(LinkedListNode<T> node)
        {
            LinkedListNode<T> temp = Head;
            Head = node;
            Head.Next = temp;
            Count++;

            if (Count == 1)
            {
                Tail = Head;
            }
        }

        //Adds the value to the end of the list
        public void AddLast(T value)
        {
            AddLast(new LinkedListNode<T>(value));
        }

        //Adds the node to the end of the list
        public void AddLast(LinkedListNode<T> node)
        {
            if (Count == 0)
            {
                Head = node;
            }
            else
            {
                Tail.Next = node;
            }
            Tail = node;
            Count++;
        }
        #endregion


        #region Remove
        //removes the first node from the list
        public void RemoveFirst()
        {
            if (Count != 0)
            {
                Head = Head.Next;
                Count--;
                if (Count == 0)
                {
                    Tail = null;
                }
            }
        }

        public void RemoveLast()
        {
            if (Count != 0)
            {
                Head = null;
                Tail = null;
            }
            else
            {
                LinkedListNode<T> current = Head;
                while (current.Next != Tail)
                {
                    current = current.Next;
                }
                current.Next = null;
                Tail = current;
            }
            Count--;
        }
        #endregion

        #region ICollection
        //The number of items currently in the list
        public int Count
        {
            get;
            private set;
        }

        //Adds the specified value to the front of the list
        public void Add(T item)
        {
            AddFirst(item);
        }

        //Returns true if the list contains the specified item, false otherwise.
        public bool Contains(T item)
        {
            LinkedListNode<T> current = Head;
            while (current != null)
            {
                if (current.Value.Equals(item))
                {
                    return true;
                }
                current = current.Next;
            }
            return false;
        }

        //Copies the node values into a specified array
        public void CopyTo(T[] array, int arrayIndex)
        {
            LinkedListNode<T> current = Head;
            while (current != null)
            {
                array[arrayIndex++] = current.Value;
                current = current.Next;
            }
        }

        //True if the collection is readonly, false otherwise
        public bool IsReadOnly
        {
            get
            {
                return false;
            }
        }

        //Removes the first occurrence of the item from the list (searching from head to tail
        public bool Remove(T item)
        {
            LinkedListNode<T> previous = null;
            LinkedListNode<T> current = Head;
            while (current != null)
            {
                if (current.Value.Equals(item))
                {
                    if (previous != null)
                    {
                        previous.Next = current.Next;

                        if (current.Next == null)
                        {
                            Tail = previous;
                        }
                        Count--;
                    }
                    else
                    {
                        RemoveFirst();
                    }
                    return true;
                }
                previous = current;
                current = current.Next;
            }
            return false;
        }

        //Enumerates over the linked list values from head to tail
        System.Collections.Generic.IEnumerator<T> System.Collections.Generic.IEnumerable<T>.GetEnumerator()
        {
            LinkedListNode<T> current = Head;
            while (current != null)
            {
                yield return current.Value;
                    current = current.Next;
            }
        }

        //Enumerates over the linked list values from head to tail
        System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator()
        {
            return ((System.Collections.Generic.IEnumerable<T>)this).GetEnumerator();
        }

        public void Clear()
        {
            Head = null;
            Tail = null;
            Count = 0;
        }
        #endregion

    }//End of Linked List
}//End of Namespace
