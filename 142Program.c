Sturct  Semaphore{
  int count;
  mutex lock;
  queue_t Q;

}Semaphore_t;

Signal(Semaphore_t *S)
{
  S->lock.acquire();

  if(S->Q.isEmpty()){
  S->count++;
}
  else  {
      InsertReadyQueue(S->Q.dequeue());
    }
  S->lock.release();
}

wait(Semaphore *S)
{
  S->lock.acquire();
  if(S->count <= 0)
  {
  S->Q.enqueue(CurrentProcess);
  S->lock.release();
  Scheduler();
  }
  else
    {
      S->count--;
     }
  }





/// different assignment

//shared mamory
int read_count
mutex_t read_lock;
semaphore_t writer = 1;

WRITER(){
    wait(writer);
    Write MEMORY;
    signal(writer);
  }

READER(){
  lock(read_lock);
  if(read_count == 0){
      wait(writer);
  }
  read_count ++;
  unlock(read_lock);
  READ DATA; 
  //decrement is a critical section so we need to protect & lock it.
  lock(read_lock);
  if(read_counter == 1){
    signal(writer);
  }
  read_count --;
  unlock(read_lock);
}












