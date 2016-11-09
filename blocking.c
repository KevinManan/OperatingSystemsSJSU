
//lock is mutex. 
struct semaphone{
	int count;
	mutex_tlock;
	queue_t Q; 
}semaphone_t;

signal(semaphone){
	s->Lock.acquire();
	if(s->Q.isEmpty()){
		s->count++;
	}else{
		InsertReadyQueue(s->Q.dequeue());
	}
	s->Lock.release();
}

wait(semaphone_t *s){
	s->Lock.acquire();
	if(s->count<=0){
		s->Q.enqueue(CurrentProcess); //psueudo code
		s->Lock.release();
		Scheduler();
	} else{
		s->count --;
		s->Lock.release();
	}
}