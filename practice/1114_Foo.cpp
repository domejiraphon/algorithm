/*
1114. Print in Order
Suppose we have a class:

public class Foo {
  public void first() { print("first"); }
  public void second() { print("second"); }
  public void third() { print("third"); }
}
The same instance of Foo will be passed to three different threads. Thread A will call first(), thread B will call second(), and thread C will call third(). Design a mechanism and modify the program to ensure that second() is executed after first(), and third() is executed after second().

Note:

We do not know how the threads will be scheduled in the operating system, even though the numbers in the input seem to imply the ordering. The input format you see is mainly to ensure our tests' comprehensiveness.
*/
class Foo {
  bool callFirst=false;
  bool callSecond=false;
  pthread_mutex_t firstMutex;
  pthread_mutex_t secondMutex;
  pthread_cond_t waitFirst;
  pthread_cond_t waitSecond;
public:
  Foo() {
    pthread_mutex_init(&firstMutex, NULL);
    pthread_mutex_init(&secondMutex, NULL);
    pthread_cond_init(&waitFirst, NULL);
    pthread_cond_init(&waitSecond, NULL);
  }

  void first(function<void()> printFirst) {
    
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    pthread_mutex_lock(&firstMutex);
    callFirst = true;
    pthread_mutex_unlock(&firstMutex);
    pthread_cond_signal(&waitFirst);
  }

  void second(function<void()> printSecond) {
    pthread_mutex_lock(&firstMutex);
    while(!callFirst)
      pthread_cond_wait(&waitFirst, &firstMutex);
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    callSecond = true;
    pthread_mutex_unlock(&firstMutex);
    pthread_cond_signal(&waitSecond);
  }

  void third(function<void()> printThird) {
    pthread_mutex_lock(&firstMutex);
    while(!callSecond)
      pthread_cond_wait(&waitSecond, &firstMutex);
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
    pthread_mutex_unlock(&firstMutex);
  }
};
