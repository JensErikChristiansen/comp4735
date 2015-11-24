/* Semaphores & Mutexes */
table_ready;
table_occupied;
table_space_available;
packing_space;
counter_available;
customer_ready;
cashier_ready;
counter_occupied;
get_burger;


Cook {
	while (true) {
		makeBurger();
		lock (table_ready) {
			lock(table_space_available) {
				placeBurgerOnTable();
			}
		}
	}
}

Packer {
	while(true) {
		lock (table_occupied) {
			lock (packing_space) {
				packBurger();
			}
		}

		lock (counter_available) {
			placeBurgerOnCounter();
		}
	}
}

Cashier {
	while(true) {
		lock (customer_ready) {
			takeOrderFromCustomer();
			takeMoney();
		}
	}
}

Customer {
	goToRestaurant();
	lock (cashier_ready) {
		orderBurger();
		pay();
	}
	
	lock (counter_occupied) {
		lock (get_burger) {
			getBurger();
		}
	}
	eatBurger();
	leave();

}
