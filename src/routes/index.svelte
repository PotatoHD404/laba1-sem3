<script>
  import Button from '../components/theme_toggle.svelte';
  import { onMount } from 'svelte';
  onMount(() => {
    exported.onLoad();
  });
  let exported;

</script>
<nav class='flex items-center justify-between flex-wrap bg-teal-500 p-6'>
  <div class='flex items-center flex-shrink-0 text-white mr-6'>
    <img src='/favicon.png' alt='Beautiful image' class='w-10 mr-2'>
    <span class='font-semibold text-xl tracking-tight'>PotatoHD's lab</span>
  </div>
  <div class='block lg:hidden'>
    <Button bind:exported={exported}>
      Theme
    </Button>
  </div>
</nav>
<header>
  <div>

  </div>

</header>
<div class='grid grid-cols-3 gap-4 mt-8'>

  <div class='col-span-2 flex justify-center'>
    <textarea class='console'></textarea>
  </div>
</div>

<style>
    .console {
        @apply resize-y border rounded-md dark:bg-black;
    }

    :global(body.dark) .console {
        @apply bg-black;
    }

    body {
        @apply m-auto;
    }

    :global(body) {
        background-color: #f2eee2;
        color: #0084f6;
        transition: background-color 0.3s
    }

    /*:global(.dark) {*/
    /*    background-color: #1d3040;*/
    /*    color: #bfc2c7;*/
    /*}*/
    :global(body.dark) {
        background-color: #1d3040;
        color: #bfc2c7;
    }

    /*.btn {*/
    /*    @apply text-base font-medium rounded-lg p-3;*/
    /*}*/

    /*.btn--primary {*/
    /*    @apply bg-rose-500 text-white;*/
    /*}*/

    /*.btn--secondary {*/
    /*    @apply bg-gray-100 text-black;*/
    /*}*/
</style>
