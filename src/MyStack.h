#ifndef MYSTACK_H_INCLUDED
#define MYSTACK_H_INCLUDED

template<typename T>
class MyStack {
    private:
        struct Element {
            Element* prev = nullptr;
            T data;

            Element(T& data)
            :   data(data)
            { }
        };

        int count    = 0;
        Element* first = nullptr;

    public:
        ~MyStack() {
            clear();
        }

        void clear() {
            while(count != 0)
                pop();
        }

        int size() const {
            return count;
        }

        bool empty() const {
            return count == 0;
        }

        void push(T& data) {
            if(count == 0) {
                Element* elem = new Element(data);

                first = elem;
                count++;
                return;
            }

            Element* temp = new Element(data);
            temp->prev = first;
            first = temp;
            count++;
        }

        bool pop() {
            if(count == 0) {
                return false;
            }
            else if(count == 1) {
                count--;
                delete first;
                return true;
            }

            Element* temp = first;
            first = temp->prev;
            count--;
            delete temp;

            return true;
        }

        T& top() {
            if(count != 0)
                return first->data;
        }


};

#endif // MYSTACK_H_INCLUDED
