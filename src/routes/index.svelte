<script>
  import { onMount } from 'svelte';
  import { theme } from '../stores/themeStore';


  onMount(() => {
      theme.subscribe((value) => {
        if (localStorage == null || localStorage.getItem('theme') == null)
          localStorage.setItem('theme', 'dark');
        else if (value === '' && localStorage.getItem('theme') != null)
          theme.set(localStorage.getItem('theme'));
        else {
          if (value === 'light')
            index = 1;
          document.body.classList.remove('light');
          document.body.classList.remove('dark');
          document.body.classList.add(value);
          localStorage.setItem('theme', value);
        }

      });
    }
  );
  const themes = ['dark', 'light'];
  const icons = ['🌙', '🌞'];
  let index = 0;


</script>

<nav class='flex items-center justify-between flex-wrap bg-teal-500 p-6'>
  <div class='flex items-center flex-shrink-0 text-white mr-6'>
    <img src='/favicon.png' alt='Beautiful image' class='w-10 mr-2'>
    <span class='font-semibold text-xl tracking-tight text-black dark:text-white'>
      PotatoHD's lab
    </span>
  </div>
  <div class='block'>
    <button on:click={() => { index = (index + 1) % themes.length; theme.set(themes[index]) }}>{icons[index]}</button>
  </div>
</nav>
<header>
  <div>

  </div>

</header>
<div class='grid grid-cols-3 gap-4 mt-8'>

  <div class='col-span-2 flex justify-center'>
    <textarea class='console dark:bg-gray-900'></textarea>
  </div>
</div>


<style>
    :global(body) {
        @apply m-auto transition-colors duration-300 bg-gray-700;
    }

    :global(body.light) {
        @apply bg-gray-100;
    }

</style>

