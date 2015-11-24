/* Semaphores & Mutexes */
sem_cooks_ready = n;
sem_packers_ready = n;
sem_cashier_ready = 1;
sem_customer_ready = 0;
sem_table_ready = n;
sem_table_occupied = n;
sem_counter_occupied = 0;
sem_counter_available = n;
mut_table_space_available[] = n;
mut_packing = 0;
mut_get_burger[] = n;

Cook {
	while (true) {
		makeBurger();
		wait(sem_table_ready);
		wait(mut_table_space_available);
		placeBurgerOnTable();
		signal(mut_table_space_available);
		signal(sem_table_occupied);
	}
}

Packer {
	while(true) {
		wait(sem_table_occupied);
		wait(mut_packing);
		packBurger();
		signal(mut_packing);
		signal(sem_table_ready);
		wait(sem_counter_available);
		placeBurgerOnCounter();
		signal(sem_counter_occupied);
	}
}

Cashier {
	while(true) {
		wait(sem_customer_ready);
		takeOrderFromCustomer();
		takeMoney();
		signal(cashier_ready);
	}
}

Customer {
	goToRestaurant();
	signal(sem_customer_ready);
	wait(sem_cashier_ready);
	orderBurger();
	pay();
	wait(sem_counter_occupied);
	wait(mut_get_burger);
	getBurger();
	signal(mut_get_burger);
	signal(sem_counter_available);
	eatBurger();
	leave();

}
