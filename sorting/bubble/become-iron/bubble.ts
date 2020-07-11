export function bubbleSort(array: Array<string | number>): Array<string | number> {
  // eslint-disable-next-line no-constant-condition
  while (true) {
    let sorted = true

    for (let i = 0; i < array.length - 1; i++) {
      const item = array[i]
      const nextItem = array[i + 1]

      if (item > nextItem) {
        sorted = false
        // swap items
        array[i] = nextItem
        array[i + 1] = item
      }
    }

    if (sorted) {
      return array
    }
  }
}

console.log(bubbleSort([1, 3, -1, 100, 14, 32]))
console.log(bubbleSort(['23', 'sdf', '123', '3ds']))
