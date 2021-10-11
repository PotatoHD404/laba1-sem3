<script>
  import Input from '../components/input.svelte';
  import Select from '../components/select.svelte';
  import { onMount } from 'svelte';

  let worker;
  let ok = false;
  let consoleText = '';
  let type_selected = false;
  onMount(async () => {
    worker = new Worker('scripts/service-worker.scripts', { type: 'module' });
    worker.onmessage = (e) => {
      if (e && e.data) {
        print(e.data);
      }
    };
    worker.postMessage('init');
    ok = true;
    console.log("initialized");
  });


  // fetchWorker.onmessage = ({ data: { status, data } }) => {
  //   if (status) loadState.status = status;
  //   if (data) dataParsed = data;
  //   if (status && status === "done") fetchWorker.terminate();
  // };

  // worker.postMessage('init');

  function Command(input, choice) {

    if (ok) {
      ok = false;
      switch (input) {
        case 'type':
          choice = choice.replace(/\s/g, '');
          console.log(choice);
          switch (choice) {
            case 'int':
              choice = '1';
              break;
            case 'float':
              choice = '2';
              break;
            case 'strings':
              choice = '3';
              break;
            case 'complex':
              choice = '4';
              break;
          }
          worker.postMessage(choice + '\n' + '4');
          type_selected = true;
          break;
        case 'init':
          switch (choice) {
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
          worker.postMessage('2' + '\n' + choice + '\n' + '4');
          break;
        case 'remove':
          worker.postMessage('3' + '\n' + choice + '\n' + '4');
          break;
        case 'fill':
          worker.postMessage('5' + '\n' + choice + '\n' + '4');
          break;
        case 'sort':
          switch (choice) {
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
    console.log(data);
    if (data.includes('Sequence: ['))
      document.getElementById('Sequence').value = data.split('Sequence: ')[1];
    else if (data.includes('Result: '))
      document.getElementById('result').value = data.split('Result: ')[1];

    consoleText += data + '\r\n';
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
      readonly>{consoleText}</textarea>
      {#if !type_selected}
        <Select text='Select type for sequence' command={(choice)=>{Command('type', choice);}}
                button_text='Select' id='type' options={['int', 'float', 'string', 'complex']} />
      {:else}
        <div class='my-2 w-full flex flex-wrap justify-center pt-2' id='menu'>
          <Input text='Add value to sequence' command={(choice)=>{Command('input',choice);}}
                 button_text='Add' />
          <Input text='Remove value from sequence' command={(choice)=>{Command('remove',choice);}}
                 button_text='Remove' />
          <Input text='Fill sequence with random numbers' command={(choice)=>{Command('fill',choice);}}
                 button_text='Fill' />
          <Select text='Init sequence with' command={(choice)=>{Command('init',choice);}}
                  button_text='Init' options={['ListSequence', 'ArraySequence']} />
          <Select text='Sort sequence' command={(choice)=>{Command('sort',choice);}}
                  button_text='Sort' options={['QuickSort', 'ShellSort', 'InsertionSort']} />
        </div>
      {/if}
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

