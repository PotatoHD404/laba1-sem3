<script>
  import Input from '../components/input.svelte';
  import { consoleText } from '../stores/consoleStore';

  let worker = new Worker('/workers/main.main.worker.js', { type: 'module' });
  let ok = false;
  worker.addEventListener('message', (e) => {
    if (e && e.data) {
      print(e.data);
    }
  });
  worker.postMessage('init');
  let array = [...Array(2).keys()];
  // const char *MSGS[] = {"0. Quit",
  //   "1. Int",
  //   "2. Float",
  //   "3. String",
  //   "4. Complex"};
  //
  //
  // const char *MSGS1[] = {"0. Quit",
  //   "1. Init sequence",
  //   "2. Add value to sequence",
  //   "3. Remove value from sequence",
  //   "4. Print sequence",
  //   "5. Fill with random values",
  //   "6. Sort"};
  //
  // const char *MSGS2[] = {"0. Quit",
  //   "1. ListSequence",
  //   "2. ArraySequence"};
  //
  // const char *MSGS3[] = {"0. Quit",
  //   "1. QuickSort",
  //   "2. ShellSort",
  //   "3. InsertionSort"};
  function Command(input) {
    if (ok) {
      ok = false;
      let choice;
      switch (input) {
        case 'type':
          let mess;
          switch (document.getElementById('typeSelect').value) {
            case 'int':
              mess = '1';
              break;
            case 'float':
              mess = '2';
              break;
            case 'strings':
              mess = '3';
              break;
            case 'complex':
              mess = '4';
              break;
          }
          worker.postMessage(mess + '\n' + '4');
          document.getElementById('type').classList.add('d-none');
          document.getElementById('menu').classList.remove('d-none');
          break;
        case 'init':
          switch (document.getElementById('typeSelect').value) {
            case 'ListSequence':
              choice = '1';
              break;
            case 'ArraySequence':
              choice = '2';
              break;
          }
          worker.postMessage('1' + '\n' + choice + '\n' + '4');
          break;
        case 'input':
          worker.postMessage('2' + '\n' + document.getElementById('seqInput').value + '\n' + '4');
          break;
        case 'remove':
          worker.postMessage('3' + '\n' + document.getElementById('seqRemove').value + '\n' + '4');
          break;
        case 'fillRandom':
          worker.postMessage('5' + '\n' + document.getElementById('seqFill').value + '\n' + '4');
          break;
        case 'sort':
          switch (document.getElementById('sortSelect').value) {
            case 'QuickSort':
              choice = '1';
              break;
            case 'ShellSort':
              choice = '2';
              break;
            case 'InsertionSort':
              choice = '3';
              break;
          }
          worker.postMessage('6' + '\n' + choice + '\n' + '4');
          break;
      }
    }
  }

  function print(data) {
    ok = true;
    // console.log(data);
    if (data.includes('Sequence: ['))
      document.getElementById('Sequence').value = data.split('Sequence: ')[1];
    else if (data.includes('Result: '))
      document.getElementById('result').value = data.split('Result: ')[1];

    document.getElementById('consoleOutput').innerHTML += data + '\r\n';
    let textarea = document.getElementById('consoleOutput');
    let temp = textarea.scrollTop;
    let interval = setInterval(() => {
      let end = textarea.scrollHeight;
      if (temp < end) {
        textarea.scrollTop += 50;
        temp += 50;
      } else {
        clearInterval(interval);
      }
    }, 5);

  }
</script>

<div class='flex justify-center'>
  <div class='flex justify-center md:w-full xl:w-2/3 2xl:w-1/2'>
    <div class='flex justify-center flex-wrap md:w-2/3 w-full'>
    <textarea
      class='px-2 py-2 flex console bg-light ring-1 ring-outline-light dark:bg-deep-black dark:text-gray-200
       rounded-md w-full focus:outline-none h-44 dark:ring-outline-dark m-1'
      readonly>$consoleText</textarea>
      <div class='my-2 w-full flex flex-wrap justify-center pt-2'>
          <Input />
      </div>


    </div>

  </div>
</div>


<style>
    .greenBox {
        background-color: rgba(0, 255, 0, 0.2);
    }

    :global(body) {
        @apply m-auto transition-colors duration-300 bg-dark;
    }

    :global(body.light) {
        @apply bg-white;
    }

</style>

