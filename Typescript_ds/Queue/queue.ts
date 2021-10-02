
 export class Queue<T>{
    private data: { [index: number]: T } = Object.create(null);
    private nextEnqueueIndex = 0;
    private lastDequeuedIndex = 0;
  
 
    enqueue(item: T): void {
      this.data[this.nextEnqueueIndex] = item;
      this.nextEnqueueIndex++;
    }
  
 
    dequeue(): T | undefined {
      if (this.lastDequeuedIndex !== this.nextEnqueueIndex) {
        const dequeued = this.data[this.lastDequeuedIndex];
        delete this.data[this.lastDequeuedIndex];
        this.lastDequeuedIndex++;
        return dequeued;
      }
    }
  
    
    size(): number {
      return this.nextEnqueueIndex - this.lastDequeuedIndex;
    }
  }