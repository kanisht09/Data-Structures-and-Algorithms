import { LinkedList } from "./Linkedlist";
const list = new LinkedList<number>();
list.add(1);
list.add(3);
list.add(9);
list.add(39);

for (let it of list.values()) {
  console.log(it);
}

list.dequeue();
console.log("\n ");
for (let it of list.values()) {
  console.log(it);
}
