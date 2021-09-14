<script>
  import Input from '../components/input.svelte';

  let array = [...Array(2).keys()];

</script>

<div class='flex justify-center'>
  <div class='flex justify-center md:w-full xl:w-2/3 2xl:w-1/2'>
    <div class='flex justify-center flex-wrap md:w-2/3 w-full'>
    <textarea
      class='px-2 py-2 flex console bg-light ring-1 ring-outline-light dark:bg-deep-black dark:text-gray-200
       rounded-md w-full focus:outline-none h-44 dark:ring-outline-dark m-1'
      readonly>blabla</textarea>
      <div class='my-2 w-full flex flex-wrap justify-center pt-2'>
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

