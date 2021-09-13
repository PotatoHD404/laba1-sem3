<script>
  import Input from '../components/input.svelte';

  let array = [...Array(1).keys()];

</script>

<div class='flex justify-center'>
  <div class='flex justify-center w-2/3'>
    <div class='flex justify-center flex-wrap w-2/3'>
    <textarea
      class='px-2 py-2 flex console bg-light ring-1 ring-outline-light dark:bg-deep-black dark:text-gray-200
       rounded-md w-full focus:outline-none h-44 dark:ring-outline-dark'
      readonly>blabla</textarea>
      <div class='my-2 w-full flex flex-wrap justify-center'>
        {#each array as item}

          <Input />
        {/each}
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

