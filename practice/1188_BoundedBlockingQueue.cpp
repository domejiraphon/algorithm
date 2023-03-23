/*
1188. Design Bounded Blocking Queue

Implement a thread-safe bounded blocking queue that has the following methods:

BoundedBlockingQueue(int capacity) The constructor initializes the queue with a maximum capacity.
void enqueue(int element) Adds an element to the front of the queue. If the queue is full, the calling thread is blocked until the queue is no longer full.
int dequeue() Returns the element at the rear of the queue and removes it. If the queue is empty, the calling thread is blocked until the queue is no longer empty.
int size() Returns the number of elements currently in the queue.
Your implementation will be tested using multiple threads at the same time. Each thread will either be a producer thread that only makes calls to the enqueue method or a consumer thread that only makes calls to the dequeue method. The size method will be called after every test case.
*/
class BoundedBlockingQueue {
  pthread_mutex_t mutexQueue;
  pthread_cond_t emptyQueue;
  pthread_cond_t fullQueue;
  int leftCap;
  queue<int> Q;
public:
  BoundedBlockingQueue(int capacity) {
    pthread_mutex_init(&mutexQueue, NULL);
    pthread_cond_init(&emptyQueue, NULL);
    pthread_cond_init(&fullQueue, NULL);
    leftCap = capacity;
  }

  void enqueue(int element) {
    pthread_mutex_lock(&mutexQueue);
    while (leftCap == 0)
      pthread_cond_wait(&fullQueue, &mutexQueue);
    Q.push(element);
    leftCap--;
    pthread_mutex_unlock(&mutexQueue);
    pthread_cond_signal(&emptyQueue);
  }

  int dequeue() {
    pthread_mutex_lock(&mutexQueue);
    while (Q.empty())
      pthread_cond_wait(&emptyQueue, &mutexQueue);
    int out = Q.front();
    Q.pop();
    leftCap++;
    pthread_mutex_unlock(&mutexQueue);
    pthread_cond_signal(&fullQueue);
    return out;
  }

  int size() {
    pthread_mutex_lock(&mutexQueue);
    int out = Q.size();
    pthread_mutex_unlock(&mutexQueue);
    return out;
  }
};
