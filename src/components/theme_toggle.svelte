<!--  Exported it just to show how to export things -->
<script>
  export const exported = {
    onLoad() {
      if (localStorage.theme === 'dark' || (!('theme' in localStorage) && window.matchMedia('(prefers-color-scheme: dark)').matches)) {
        window.document.body.classList.add('dark');
      } else {
        window.document.body.classList.remove('dark');
      }
    }
  };

  // export async function load() {
  //   exported.onLoad();
  // }


  function toggle() {
    if (localStorage.theme === 'light') {
      localStorage.theme = 'dark';
    } else {
      localStorage.theme = 'light';
    }
    exported.onLoad();

  }
</script>
<button on:click={toggle}>
  <slot />
</button>
<style>
    button {
        background-color: #f76027;
        color: white;
        border: none;
        border-radius: 4px;
        padding: 0.5rem;
        text-transform: uppercase;

    }

    :global(body.dark) button {
        background-color: #0084f6;
        color: white;
    }
</style>