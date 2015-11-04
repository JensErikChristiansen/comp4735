_numResources = 0;
Queue Q

initialize (numResources) {
	_numResources = numResources;
	Q = 0;
}

Signal() {
	/* Stop using resource */
	_numResources++;
	if (Q.count <= 0) {
		/* remove a process P from s.queue; */
		/* place process P on ready list; */
	}
}

Wait() {
	_numResources--;
	if (_numResources < 0) {
		/* Use resource; */
		/* Block this process; */
	} else {
		add to Q;
	}
	
}