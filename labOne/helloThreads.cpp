#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <unistd.h>

/*! displays a message first */
void taskOne(std::shared_ptr<Semaphore> theSemaphore, int delay) {
  theSemaphore->Wait();
  sleep(delay);
  std::cout << "I ";
  std::cout << "must ";
  std::cout << "print ";
  std::cout << "first" << std::endl;
  theSemaphore->Signal();
  //theSemaphore.release();
  // Signal that taskOne has finished
}

/*! displays a message second */
void taskTwo(std::shared_ptr<Semaphore> theSemaphore) {
  // Wait for taskOne to finish
  theSemaphore->Wait();
  // theSemaphore.acquire();
  // Wait for a bit to ensure proper sequencing
  sleep(1);
  std::cout << "This ";
  std::cout << "will ";
  std::cout << "appear ";
  std::cout << "second" << std::endl;
  theSemaphore->Signal();
}

int main(void) {
  std::thread threadOne;
  std::thread threadTwo;
  std::shared_ptr<Semaphore> sem(new Semaphore);

  /**< Launch the threads */
  int taskOneDelay = 5;
  threadOne = std::thread(taskTwo, sem);
  threadTwo = std::thread(taskOne, sem, taskOneDelay);

  std::cout << "Launched from the main\n";

  /**< Wait for the threads to finish */
  threadOne.join();
  threadTwo.join();

  return 0;
}
